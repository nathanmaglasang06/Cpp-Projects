
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 1000}), "Falling Sphere");
    sf::CircleShape obj(10.f);
    obj.setFillColor(sf::Color::Black);
    obj.setOutlineThickness(-3.f);
    obj.setOutlineColor(sf::Color(255,255,255));
    obj.setPosition({395.f, 50.f});


    sf::Vector2f velocity({0.f, 0.f});
    sf::Vector2f terminal({0.f, 100.f});
    sf::Vector2f gravity({0.f, .98f});
    sf::Vector2f pos = obj.getPosition();
    sf::Font font("ARIAL.TTF");
    sf::Text text(font);
   text.setString("Velocity: " + std::to_string(velocity.y));


bool bounce = true;


    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

    while (bounce){
            window.setFramerateLimit(60);

    const float windowHeight = static_cast<float>(window.getSize().y);
    const sf::FloatRect bounds = obj.getGlobalBounds(); // SFML 3: has .position and .size
    const float objBottom = bounds.position.y + bounds.size.y;

       if (objBottom >= windowHeight) {
                    obj.setPosition({ obj.getPosition().x, windowHeight - bounds.size.y });

           if (std::abs(velocity.y) < 0.033f){
                gravity.y = 0.f;
                velocity.y = 0.f;
                bounce = false;
                break;
            } else {
                velocity.y = -velocity.y * 0.9f;

            }

        }
        velocity += gravity;
        text.setString("Velocity:  " + std::to_string(velocity.y));


        if (velocity.y > terminal.y){
            velocity.y = terminal.y;
        }

        obj.move(velocity);
         window.clear();
         window.draw(text);

        window.draw(obj);
        window.display();
    }
bounce = false;

        window.clear();
        window.draw(text);

        window.draw(obj);
        window.display();
    }
}
