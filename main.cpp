#include <iostream>
#include <SFML/Graphics.hpp>
#include "ui/Container.h"
#include "ui/Utils.h"
#include "ui/elements/TextNode.h"
#include "ui/elements/Button.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "XEP GOVNO");

    gui::Container container;
    container.setBackgroundColor(sf::Color::Red);
    container.setWindow(&window);

    container.setPosition(100, 100);
    container.setSizeMode(gui::Container::SizeMode::WRAP_CONTENT);

    TextNode textNode;
    textNode.setText("TES VI");
    textNode.setMarginBottom(40);

    container.add(&textNode);


    gui::Container title;
    title.setBackgroundColor(sf::Color::Black);
    title.setSize(100, 50);
    title.setMarginBottom(30);

    container.add(&title);

    gui::Container child;
    child.setSize({100, 100});
    child.setBackgroundColor(sf::Color::Green);

    container.add(&child);

    gui::Container child2;
    child2.setSize({100, 100});
    child2.setBackgroundColor(sf::Color::Yellow);
    container.add(&child2);

    container.setAlignment(gui::Container::Alignment::CENTER, gui::Container::Alignment::CENTER);
    container.setCenterHorizontal(true);
    container.setBottomInparent(true);

    sf::RectangleShape line({window.getSize().x, 1});
    line.setFillColor(sf::Color::Black);
    line.setPosition(0,window.getSize().y / 2);


    sf::RectangleShape vLine({1, window.getSize().y});
    vLine.setFillColor(sf::Color::Black);
    vLine.setPosition(window.getSize().x / 2, 0);

    Button button("Button");
    button.setPosition(100, 100);

  /*  gui::Container child3;
    child3.setSize({100, 150});
    child3.setBackgroundColor(sf::Color::Black);
    container.add(&child3);*/


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        window.draw(container);
        window.draw(line);
        window.draw(vLine);
        window.draw(button);
        window.display();
    }

    return 0;
}