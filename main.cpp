#include"main.h"
#include"matplotlibcpp.h"
#include"Planet.h"
#include"Vec2D.h"
#include"Solar_System.h"


using namespace std;
namespace plt = matplotlibcpp;


//Fucntion used to draw a single planet
void draw_planet(double t, planet Planet){
    plt::figure_size(800, 800);
    vector < double > x_last={Planet.get_pos().get_x()/149597871000.0};
    vector < double > y_last={Planet.get_pos().get_y()/149597871000.0};
    cout << y_last[0] << " " << x_last[0];
    plt::scatter(x_last,y_last,40); // plot last postion as a point
    vector < double > sx;
    vector < double > sy;
    sx.push_back(0);
    sy.push_back(0);
    plt::scatter(sx,sy,30); // plot position of the Sun as a point
    plt::title("Day "+to_string(int(t)));
    plt::xlabel("x [AU]");
    plt::ylabel("y [AU]");
    plt::xlim(-40,40);
    plt::ylim(-40,40);
    plt::save("plots/t="+to_string(int(t))+".png");
    plt::close();
}

/* 
//Code to draw a single planet

int main(){

    vec2d earth_pos_0(x_0, y_0);
    vec2d earth_vel_0(v_x_0, v_y_0);

    planet earth(earth_pos_0, earth_vel_0, "Earth");

    double t = 0;

    draw_planet(t, earth);

    for(int i; i < 100000; i++){
        t += dt;
        earth.delta_t();
    }

    draw_planet(t, earth);


    return 0;
}
*/

int main(){

    solar_system solar(dt);

    solar.from_file();

    for(int i = 0; i <= t_max; i = i + dt){

        if(i % (t_max / 10) == 0){
            solar.draw();
        } 

        solar.system_evolve();

    }

    return 0;
}