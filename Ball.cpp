#include "Ball.h"
#include <iostream>

Ball::Ball(TDT4102::Color color, double vel_x, double vel_y, double pos_x, double pos_y, int radius) 
: Entity(color, vel_x, vel_y, pos_x, pos_y, radius*radius*3.14159), radius{radius}, centre{int(std::round(pos_x)), int(std::round(pos_y))} {}

void Ball::bounce_x() {
    vel_x = - vel_x * e;
}

void Ball::bounce_y() {
    vel_y = - vel_y * e;
}

void Ball::ball_collision(Ball& other) {
    //future positions
    double future_x = pos_x + vel_x * dt;
    double other_future_x = other.pos_x + other.vel_x * dt;
    double future_y = pos_y + vel_y * dt;
    double other_future_y = other.pos_y + other.vel_y * dt;

    //checking distance between
    double dx = other_future_x - future_x;
    double dy = other_future_y - future_y;
    double dist = sqrt(pow(dx, 2) + pow(dy, 2));
    double min_dist = radius + other.radius;
    if (dist >= min_dist) return;
    //else

    //little bit of physics 
    //n is the collision normal: p2 - p1 / ||p2 - p1|| where p is the position vectors (math)
    if (dist == 0) return;
    double n_x = dx / dist;
    double n_y = dy / dist;
    
    //Relative velocity along the normal. scalar. (v1 - v2)*n where v and n are vectors
    double v_rel = (vel_x - other.vel_x)*n_x + (vel_y - other.vel_y)*n_y;
    if (v_rel < 0) return; //then they are already moving away from eachother.

    double inverse_masses = 1.0 / mass + 1.0 / other.mass;
    //impulse scalar j
    double j = - ((1.0 + e) * v_rel) / (inverse_masses);

    //formula for new speed: 
    // v = v + j/m * n
    //which gives:
    vel_x += j / mass * n_x;
    vel_y += j / mass * n_y;
    other.vel_x -= j / other.mass * n_x;
    other.vel_y -= j / other.mass * n_y;
}
