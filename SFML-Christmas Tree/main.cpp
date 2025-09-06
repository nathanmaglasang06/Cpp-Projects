#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main() {
  sf::RenderWindow window(sf::VideoMode({200, 300}), "SFML with Homebrew Setup Guide");
  sf::CircleShape shape1(10.f);
  shape1.setFillColor(sf::Color::Blue);
  shape1.setPosition(sf::Vector2f(90.f, 30.f));

  sf::CircleShape shape2(10.f);
  shape2.setFillColor(sf::Color::Red);
  shape2.setPosition(sf::Vector2f(70.f, 80.f));

  sf::CircleShape shape3(10.f);
  shape3.setFillColor(sf::Color::Blue);
  shape3.setPosition(sf::Vector2f(50.f, 130.f));

  sf::CircleShape shape4(10.f);
  shape4.setFillColor(sf::Color::Red);
  shape4.setPosition(sf::Vector2f(30.f, 180.f));

  sf::CircleShape shape5(10.f);
  shape5.setFillColor(sf::Color::Red);
  shape5.setPosition(sf::Vector2f(90.f, 130.f));

  sf::CircleShape shape6(10.f);
  shape6.setFillColor(sf::Color::Blue);
  shape6.setPosition(sf::Vector2f(110.f, 80.f));

  sf::CircleShape shape7(10.f);
  shape7.setFillColor(sf::Color::Blue);
  shape7.setPosition(sf::Vector2f(130.f, 130.f));

  sf::CircleShape shape8(10.f);
  shape8.setFillColor(sf::Color::Red);
  shape8.setPosition(sf::Vector2f(150.f, 180.f));

  sf::CircleShape shape9(10.f);
  shape9.setFillColor(sf::Color::Blue);
  shape9.setPosition(sf::Vector2f(90.f, 180.f));


  sf::CircleShape shape1b(10.f);
  shape1b.setFillColor(sf::Color::Red);
  shape1b.setPosition(sf::Vector2f(90.f, 30.f));

  sf::CircleShape shape2b(10.f);
  shape2b.setFillColor(sf::Color::Blue);
  shape2b.setPosition(sf::Vector2f(70.f, 80.f));

  sf::CircleShape shape3b(10.f);
  shape3b.setFillColor(sf::Color::Red);
  shape3b.setPosition(sf::Vector2f(50.f, 130.f));

  sf::CircleShape shape4b(10.f);
  shape4b.setFillColor(sf::Color::Blue);
  shape4b.setPosition(sf::Vector2f(30.f, 180.f));

  sf::CircleShape shape5b(10.f);
  shape5b.setFillColor(sf::Color::Blue);
  shape5b.setPosition(sf::Vector2f(90.f, 130.f));

  sf::CircleShape shape6b(10.f);
  shape6b.setFillColor(sf::Color::Red);
  shape6b.setPosition(sf::Vector2f(110.f, 80.f));

  sf::CircleShape shape7b(10.f);
  shape7b.setFillColor(sf::Color::Red);
  shape7b.setPosition(sf::Vector2f(130.f, 130.f));

  sf::CircleShape shape8b(10.f);
  shape8b.setFillColor(sf::Color::Blue);
  shape8b.setPosition(sf::Vector2f(150.f, 180.f));

  sf::CircleShape shape9b(10.f);
  shape9b.setFillColor(sf::Color::Red);
  shape9b.setPosition(sf::Vector2f(90.f, 180.f));

  sf::RectangleShape treebase(sf::Vector2f(20.f, 85.f));
  treebase.setFillColor(sf::Color(139, 69, 19));
  treebase.setPosition(sf::Vector2f(90.f, 215.f));

  sf::ConvexShape triangle;
  triangle.setPointCount(3);
  triangle.setPoint(0, sf::Vector2f(100.f, 10.f)); // Top vertex
  triangle.setPoint(1, sf::Vector2f(10.f, 215.f));  // Bottom-left
  triangle.setPoint(2, sf::Vector2f(190.f, 215.f)); // Bottom-righ  
  triangle.setFillColor(sf::Color::Green); // Fill color
  

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent())
      if (event->is<sf::Event::Closed>())
        window.close();

    window.clear();

    window.draw(treebase);
    window.draw(triangle);
    window.draw(shape1);
    window.draw(shape2);
    window.draw(shape3);
    window.draw(shape4);
    window.draw(shape5);
    window.draw(shape6);
    window.draw(shape7);
    window.draw(shape8);
    window.draw(shape9);
    
    window.display();
    sleep(2);

    window.clear();

    window.draw(treebase);
    window.draw(triangle);
    window.draw(shape1b);
    window.draw(shape2b);
    window.draw(shape3b);
    window.draw(shape4b);
    window.draw(shape5b);
    window.draw(shape6b);
    window.draw(shape7b);
    window.draw(shape8b);
    window.draw(shape9b);

    window.display();
    sleep(2);
  }

  return 0;
}

