    #ifndef VEC2D_H
#define VEC2D_H


#include"main.h"
#include"matplotlibcpp.h"

class vec2d{

    public:
    vec2d(); //Constructor taking no argumants
    vec2d(double a, double b); //Constructor taking x and y arguments respectively
    ~vec2d(); //Destructor

    //Methods
    double get_x(); //Returns x-coordinate
    double get_y(); //Returns y-coordinate

    void set_x(double a); 
    void set_y(double b);

    void add(vec2d vec); //Addition of a vector in argument
    void sub(vec2d vec); //Subtration of a vector in argument
    void scale(double a); // Multilpication by a scalar in argument

    //Operators
    vec2d operator+(vec2d vec); //addition operator
    vec2d operator-(vec2d vec); //Subtraction operator
    vec2d operator*(double a); //Multipication by a scalar operator

    double len();

    
    private:
    double x; //x-coordinate
    double y; //y-coordinate

};

#endif