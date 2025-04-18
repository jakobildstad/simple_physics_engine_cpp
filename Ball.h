#pragma once
#include "Entity.h"
#include "AnimationWindow.h"

struct Ball : Entity {
    TDT4102::Point centre;
    const int radius = 20;

    //walls
    double right_wall() const { return pos_x + radius + vel_x * dt; }
    double left_wall() const { return pos_x - radius + vel_x * dt; }
    double top_wall() const { return pos_y - radius + vel_y * dt; }
    double bottom_wall() const { return pos_y + radius + vel_y * dt; }

    //Constructor
    Ball(TDT4102::Color color, double vel_x = 0, double vel_y = 0, double pos_x = 550, double pos_y = 200, int radius = 20);

    //wall bounces
    void bounce_x();
    void bounce_y();
    void ball_collision(Ball& other);
};