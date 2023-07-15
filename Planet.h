    #ifndef PLANET_H
#define PLANET_H

#include"main.h"
#include"Vec2D.h"
#include"matplotlibcpp.h"

using namespace std;

class planet{

    public:
    planet(); //Constructor taking no arguments
    planet(vec2d a, vec2d b, string n); //constructor taking position vector and velocity vectors as arguments respectively
    ~planet(); //Destructor

    //Methods
    vec2d get_pos(); //Returns position vector
    vec2d get_vel(); //returns velocity vector
    string get_name(); //Returns a name of a planet as a string

    void set_pos(vec2d a); //Sets a position vector
    void set_vel(vec2d b); //Sets a velocity vecor
    void set_name(string n); //Sets a name of a planet

    void delta_t(); //Changes the position vector and velocity vector of a planet based on time increasement

    private:
    vec2d pos; //Position vector of a planet
    vec2d vel; //Velocity vector of a planet
    string name; //Name of the planet
};

#endif