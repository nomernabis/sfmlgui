//
// Created by pavel on 04.06.18.
//

#include "Utils.h"

sf::Vector2f Utils::getCenterOf(sf::RenderWindow* window) {
    sf::Vector2f center;
    center.x = window->getSize().x / 2;
    center.y = window->getSize().y / 2;
    return center;
}

float Utils::getBottomOf(sf::RenderTarget* window) {
    return window->getSize().y;
}
