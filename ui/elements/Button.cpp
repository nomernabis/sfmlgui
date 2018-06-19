//
// Created by pavel_cpp on 18.06.18.
//

#include "Button.h"

Button::Button(std::string text) {
    textNode.setText(text);
    rect.setSize({textNode.getWidth(), textNode.getHeight()});
    rect.setPosition(textNode.getPosition());
    rect.setFillColor(sf::Color::Red);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
    target.draw(textNode, states);
}

void Button::setPosition(float x, float y) {
    rect.setPosition(x, y);
    textNode.setPosition(x, y);
}

float Button::getWidth() const {
    return rect.getSize().x;
}

float Button::getHeight() const {
    return rect.getSize().y;
}