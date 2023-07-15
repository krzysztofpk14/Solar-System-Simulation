    #ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H



#include"main.h"
#include"matplotlibcpp.h"
#include"Vec2D.h"
#include"Planet.h"

using namespace std;

class solar_system{

    public:

    solar_system(double d_t); //Constructor taking time_step as an argument
    ~solar_system();          //Destructor


    //Methods
    void draw();            //Method used to generate Matplotlib figures
    void system_evolve();   //Method used to udate positons and velocities of all planets
    void to_file();         //Writes psotions and velocites of each planet to a seperate file
    void from_file();       //Reads the name and initial conditions of a plnaet to a planets vector

    private:

    vector <planet> planets; //Vector containing the elements of class planet
    double current_time;     //Current time of the simulation
    double time_step;        //Time difference between each time points

};

#endif