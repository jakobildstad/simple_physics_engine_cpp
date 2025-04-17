#include "Ball.h"
#include <iostream>

Ball::Ball(TDT4102::Color color, double vel_x, double vel_y, double pos_x, double pos_y, double mass) 
: Entity(color, vel_x, vel_y, pos_x, pos_y, mass), centre{int(std::round(pos_x)), int(std::round(pos_y))} {}

void Ball::bounce_x() {
    vel_x = - vel_x * conserving_factor;
}

void Ball::bounce_y() {
    vel_y = - vel_y * conserving_factor;
}

void Ball::ball_collision(Ball& other) {
    //checking distance between
    double dx = abs((other.pos_x + other.vel_x * dt) - (pos_x + vel_x * dt));
    double dy = abs((other.pos_y + other.vel_y * dt) - (pos_y + vel_y * dt));
    double dist = sqrt(pow(dx, 2) + pow(dy, 2));
    double min_distance = radius + other.radius;
    if (dist >= min_distance) {return;}
    //else
    std::cout << "collision" << std::endl;
}