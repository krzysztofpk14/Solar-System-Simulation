#include"main.h"
#include"Vec2D.h"
#include"Planet.h"

using namespace std;

planet::planet(){
    pos = vec2d(0, 0);
    vel = vec2d(0, 0);
    name = "";
}

planet::planet(vec2d a, vec2d b, string n){
    pos = a;
    vel = b;
    name = n;
}

planet::~planet(){

}

vec2d planet::get_pos(){
    return this->pos;
}

vec2d planet::get_vel(){
    return this->vel;
}

string planet::get_name(){
    return this->name;
}

void planet::set_pos(vec2d a){
    pos = a;
}

void planet::set_vel(vec2d b){
    vel = b;
}

void planet::set_name(string n){
    name = n;
}

void planet::delta_t(){
    pos = this->pos + this->vel * (dt * 24 * 60 * 60); //The time in days must be converted to seconds
    vel = this->vel - this->pos * (G * m_s / pow(this->pos.len(), 3) * dt * 24 * 60 * 60);
}