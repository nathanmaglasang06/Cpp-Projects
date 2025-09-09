#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main() {
  sf::RenderWindow window(sf::VideoMode({900, 900}), "SFML-Moving-Sphere");
  window.setFramerateLimit(100);

  auto Circle = sf::CircleShape(10.f);  
  Circle.setFillColor(sf::Color::Blue);
  Circle.setPosition(sf::Vector2f(90.f, 30.f));

  auto direction_vector = sf::Vector2f(0.f, 0.f);
  auto velocity = 0.1f;
  auto frame_clock = sf::Clock();
  
  enum Directions { UP = 2, DOWN = 3, LEFT = 0, RIGHT = 1 };


    auto key_states = std::vector<bool>(4, false);

    while (window.isOpen())
    {
        auto frame_time = frame_clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (auto keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                key_states[UP] = key_states[UP] || (keyPressed->code == sf::Keyboard::Key::W);
                key_states[DOWN] = key_states[DOWN] || (keyPressed->code == sf::Keyboard::Key::S);
                key_states[LEFT] = key_states[LEFT] || (keyPressed->code == sf::Keyboard::Key::A);
                key_states[RIGHT] = key_states[RIGHT] || (keyPressed->code == sf::Keyboard::Key::D);
            }
            else if (auto keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
                if (keyReleased->code == sf::Keyboard::Key::W)
                {
                    key_states[UP] = false;
                }
                else if (keyReleased->code == sf::Keyboard::Key::S)
                {
                    key_states[DOWN] = false;
                }
                else if (keyReleased->code == sf::Keyboard::Key::A)
                {
                    key_states[LEFT] = false;
                }
                else if (keyReleased->code == sf::Keyboard::Key::D)
                {
                    key_states[RIGHT] = false;
                }
            }
        }

        if ((key_states[LEFT] && key_states[RIGHT]) || (!key_states[LEFT] && !key_states[RIGHT]))
        {
            direction_vector.x = 0.f;
        }
        else if (key_states[LEFT])
        {
            direction_vector.x = -1.f;
        }
        else if (key_states[RIGHT])
        {
            direction_vector.x = 1.f;
        }

        if ((key_states[UP] && key_states[DOWN]) || (!key_states[UP] && !key_states[DOWN]))
        {
            direction_vector.y = 0.f;
        }
        else if (key_states[UP])
        {
            direction_vector.y = -1.f;
        }
        else if (key_states[DOWN])
        {
            direction_vector.y = 1.f;
        }

        Circle.move((direction_vector == sf::Vector2f{} ? sf::Vector2f{} : direction_vector.normalized()) * velocity * frame_time.asSeconds());

        window.clear();
        window.draw(Circle);
        window.display();
    }

  return 0;
}

