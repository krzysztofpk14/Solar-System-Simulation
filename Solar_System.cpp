
#include"main.h"
#include"matplotlibcpp.h"
#include"Vec2D.h"
#include"Planet.h"
#include"Solar_System.h"

using namespace std;
namespace plt = matplotlibcpp;

solar_system::solar_system(double d_t){
    time_step = d_t;
    current_time = 0;
    vector <planet> planets;
}

solar_system::~solar_system(){
}

void solar_system::draw(){
    plt::figure_size(800, 800);
    for(int i=0; i < planets.size(); i++ ){
        ifstream iplik("data/" + planets[i].get_name() + ".txt", std::ios_base::app);
        vector < double > T;
        vector < double > X;
        vector < double > Y;
            while(true){
                double tt,x,y;
                iplik >> tt >> x >> y;
                if(iplik.fail()) break;
                x = x/149597871000.0;
                y = y/149597871000.0;
                // cout << x << y << endl;
                X.push_back(x);
                Y.push_back(y);
            }
            
        iplik.close();
        vector < double > x_last={X.back()};
        vector < double > y_last={Y.back()};
        plt::scatter(x_last,y_last,20); // plot latest postion as a point
        plt::plot(X,Y); // plot all previous positions as line
    }

    vector < double > sx;
    vector < double > sy;
    sx.push_back(0);
    sy.push_back(0);
    plt::scatter(sx,sy,5); // plot position of the Sun as a point
    plt::title("Dzien "+to_string(int(current_time))); //Current time in days
    plt::xlabel("x [AU]");
    plt::ylabel("y [AU]");
    plt::xlim(-40,40);
    plt::ylim(-40,40);
    plt::save("plots/t="+to_string(int(current_time))+".png"); 
    plt::close();
    } 


void solar_system::to_file(){

    for(int i = 0; i < planets.size(); i++){

        string name = planets[i].get_name();
        std::ofstream outfile;

        if(this->current_time == 0){
            outfile.open("data/" + name + ".txt", std::ios_base::out);
        }
        else{
            outfile.open("data/" + name + ".txt", std::ios_base::app);
        }

        //Columns t, x(t), y(t)

        outfile << this->current_time << "\t" << planets[i].get_pos().get_x() << "\t" << planets[i].get_pos().get_y() << endl;
        
        outfile.close();
    }
}

void solar_system::from_file(){
    //Columns of planets.txt: name , x_0, y_0, v_x_0, v_y_0
    ifstream infile("planets.txt");

    while(true){
        string name;
        double x_0;
        double y_0;
        double v_x_0;
        double v_y_0;

        infile >> name >> x_0 >> y_0 >> v_x_0 >> v_y_0;

        if(!infile){
            break;
        }
        else{
            vec2d pos_0(x_0, y_0);
            vec2d vel_0(v_x_0, v_y_0);

            planet planet1(pos_0, vel_0, name);
            planets.push_back(planet1);
        }
    }
    infile.close();

    this->to_file(); //Save initial conditions to a file

}

void solar_system::system_evolve(){

    current_time += this->time_step;

    for(int i = 0; i < planets.size(); i++){
        planets[i].delta_t();
    }

    this->to_file();
}
