#include <iostream>
#include <SFML/Graphics.hpp>
#include "ui/Container.h"
#include "ui/MenuList.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(960, 640), "TEST");

    MenuList menuList;
    menuList.setBackgroundColor(sf::Color::Black);
    menuList.setWindow(&window);
    menuList.setBottomInparent(true);
    menuList.setCenterHorizontal(true);
    menuList.setPadding(100, 0);
    menuList.setChildSpacing(20);

    menuList.add("START");
    menuList.add("OPTIONS");
    menuList.add("EXIT");

    TextNode gameTitle;
    gameTitle.setMarginTop(150);
    gameTitle.setWindow(&window);
    gameTitle.setFontSize(40);
    gameTitle.setText("PACMAN");
    gameTitle.setTextColor(sf::Color::White);
    gameTitle.setCenterHorizontal(true);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            menuList.handleInput(event);
        }
        window.clear(sf::Color::Black);
        window.draw(gameTitle);
        window.draw(menuList);
        window.display();
    }

    return 0;
}