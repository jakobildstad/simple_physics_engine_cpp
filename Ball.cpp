#include "Ball.h"

Ball::Ball(TDT4102::Color color, double vel_x, double vel_y, double pos_x, double pos_y, double mass) 
: Entity(color, vel_x, vel_y, pos_x, pos_y, mass), centre{int(std::round(pos_x)), int(std::round(pos_y))} {}

void Ball::bounce_x() {
    vel_x = - vel_x * conserving_factor;
}

void Ball::bounce_y() {
    vel_y = - vel_y * conserving_factor;
}