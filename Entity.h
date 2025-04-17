#pragma once
#include "AnimationWindow.h"

struct Entity {
    double g = 500; //gravity strength
    const double conserving_factor = 0.95; //sqrt of how much kinetic energy is kept each bounce (0-1)
    const double mass = 10;
    const double k = 0.3; //air resistance factor
    const double dt = 1.0/60.0; //animation is 60 fps
    TDT4102::Color color;

    double vel_x = 0;
    double vel_y = 0;
    double pos_x = 550;
    double pos_y = 200;
    
    Entity(TDT4102::Color color, double vel_x, double vel_y, double pos_x, double pos_y, double mass);

    void g_update_velocity();
    void update_position();
};