#include "Entity.h"

Entity::Entity(TDT4102::Color color, double vel_x, double vel_y, double pos_x, double pos_y, double mass) 
: color{color}, vel_x{vel_x}, vel_y{vel_y}, pos_x{pos_x}, pos_y{pos_y}, mass{mass} {}

void Entity::update_velocity() {
    vel_y += g * dt;
}

void Entity::update_position() {
    pos_y += vel_y * dt;
    pos_x += vel_x * dt;
}

