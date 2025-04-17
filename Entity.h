#pragma once
#include "AnimationWindow.h"

struct Entity {
    double g = 500; //gravity strength
    const double conserving_factor = 0.95; //sqrt of how much energy is kept each bounce (0-1)
    const double dt = 1.0/60.0;
    TDT4102::Color color;

    double vel_x = 0;
    double vel_y = 0;
    double pos_x = 550;
    double pos_y = 200;
    double mass = 10;
    
    Entity(TDT4102::Color color, double vel_x, double vel_y, double pos_x, double pos_y, double mass);

    void update_velocity();
    void update_position();
};