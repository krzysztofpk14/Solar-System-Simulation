#include"main.h"
#include"matplotlibcpp.h"
#include"Vec2D.h"

//Constructor and destructor methods
vec2d::vec2d(){
    x = 0;
    y = 0;
}

vec2d::vec2d(double a, double b){
    x = a;
    y = b;
}

vec2d::~vec2d(){

}


//Methods
double vec2d::get_x(){
    return this->x;
}

double vec2d::get_y(){
    return this->y;
}

void vec2d::set_x(double a){
    x = a;
}

void vec2d::set_y(double b){
    y = b;
}

void vec2d::add(vec2d vec){
    x = this->x + vec.get_x();
    y = this->y + vec.get_y();
}

void vec2d::sub(vec2d vec){
    x = this->x - vec.get_x();
    y = this->y - vec.get_y();
}

void vec2d::scale(double a){
    x = this->x * a;
    y = this->y * a;
}


//Operators
vec2d vec2d::operator+(vec2d vec){
    vec2d vec2(this->x + vec.get_x(), this->y + vec.get_y());
    return vec2;
}

vec2d vec2d::operator-(vec2d vec){
    vec2d vec2(this->x - vec.get_x(), this->y - vec.get_y());
    return vec2;
}

vec2d vec2d::operator*(double a){
    vec2d vec2(this->x * a, this->y * a);
    return vec2;
}

double vec2d::len(){
    return sqrt(pow(this->x, 2) + pow(this->y, 2));
}