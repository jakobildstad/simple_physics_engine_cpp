#include "std_lib_facilities.h"
#include "Ball.h"
#include "widgets/Button.h"

int main() {
    //Window constants
    const int window_x = 200;
    const int window_y = 200;
    const int window_width = 1100;
    const int window_height = 600;
    const std::string window_title = "Physics engine";

    //Starting window
    TDT4102::AnimationWindow window(window_x, window_y, window_width, window_height, window_title);

    //Let there be balls
    std::vector<Ball> balls;
    balls.emplace_back(TDT4102::Color::blue,   500, -500);
    balls.emplace_back(TDT4102::Color::red,    200,  300);
    balls.emplace_back(TDT4102::Color::forest_green, -100,  700);
    balls.emplace_back(TDT4102::Color::black, 200, 100, 100, 100, 40);

    //Button
    TDT4102::Button button {{1000, 10}, 100, 50, "Energize"};
    button.setCallback([&balls]() {
        for (Ball& b : balls) {
            b.vel_x += b.vel_x * 1000 / b.mass;
            b.vel_y += b.vel_y * 1000 / b.mass;
        }
    });
    window.add(button);
    
    //Animation
    while (!window.should_close()) {
        //balls
        for (int i = 0; i < balls.size(); ++i) {
            Ball &ball = balls.at(i);
            ball.g_update_velocity();
            
            //wall collision
            if ((ball.right_wall() > window_width) || (ball.left_wall() < 0)) {
                ball.bounce_x();
            } else if ((ball.top_wall() < 0) || (ball.bottom_wall() > window_height)) {
                ball.bounce_y();
            }

            //ball collision
            for (int j = i + 1; j < balls.size(); ++j) {
                ball.ball_collision(balls.at(j));
            }

            ball.update_position();

            ball.centre.x = int(std::round(ball.pos_x));
            ball.centre.y = int(std::round(ball.pos_y));

            window.draw_circle(ball.centre, ball.radius, ball.color);
        }
        //here you could do a for-loop to iterate and update other entities

        window.next_frame();
    }
 
    return 0;
}
