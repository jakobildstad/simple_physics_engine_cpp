#include "std_lib_facilities.h"
#include "Ball.h"

int main() {
    //Window constants
    const int window_x = 200;
    const int window_y = 200;
    const int window_width = 1100;
    const int window_height = 600;
    const std::string window_title = "Physics engine";

    //Starting window
    TDT4102::AnimationWindow window(window_x, window_y, window_width, window_height, window_title);

    //Making ball pointers
    std::vector<std::unique_ptr<Ball>> balls;
    
    balls.emplace_back(std::make_unique<Ball>(TDT4102::Color::blue,   500, -500));
    balls.emplace_back(std::make_unique<Ball>(TDT4102::Color::red,    0,  300));
    balls.emplace_back(std::make_unique<Ball>(TDT4102::Color::forest_green, -100,  700));
    
    //Animation
    while (!window.should_close()) {
        for (auto &ball : balls) {
        ball->update_velocity();

        if ((ball->right_wall() > window_width) || (ball->left_wall() < 0)) {
            ball->bounce_x();
        } else if ((ball->top_wall() < 0) || (ball->bottom_wall() > window_height)) {
            ball->bounce_y();
        }

        ball->update_position();

        ball->centre.x = int(std::round(ball->pos_x));
        ball->centre.y = int(std::round(ball->pos_y));

        window.draw_circle(ball->centre, ball->radius, ball->color);
        }


        window.next_frame();
    }
 
    return 0;
}
