#include <iostream>
#include <SFML/Graphics.hpp>
#include "ui/Container.h"
#include "ui/Utils.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "XEP GOVNO");

    gui::Container container;
    container.setBackgroundColor(sf::Color::Red);
    container.setCenter(gui::Utils::getCenterOf(window));

    gui::Container child;
    child.setBackgroundColor(sf::Color::Green);
    child.setSize({200, 100});

    container.add(&child);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(container);
        window.display();
    }

    return 0;
}