//
// Created by pavel_cpp on 18.06.18.
//

#include "Button.h"

sf::Vector2f Button::getPosition() {
    return rect.getPosition();
}

void Button::setRelativePosition(float x, float y) {
    setPosition(getParentNode()->getPosition().x + x, getParentNode()->getPosition().y + y);
}

void Button::setBackgroundColor(sf::Color color) {
    rect.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
    textNode.setColor(color);
}

void Button::setFixedSize(bool isFixedSize) {
    this->isFixedSize = isFixedSize;
}

void Button::setAlignment(Alignment alignment) {
    this->alignment = alignment;
}

void Button::setText(std::string text) {
    textNode.setText(text);
    resize();
}

Button::Button(std::string text) {
    textNode.setText(text);
    rect.setSize({textNode.getWidth(), textNode.getHeight()});
    rect.setFillColor(sf::Color::Red);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(rect, states);
    target.draw(textNode, states);
}

void Button::setPosition(float x, float y) {
    sf::Vector2f positon{x, y};
    textNode.setPosition(positon - textNode.getLocalBounds());
    rect.setPosition({x, y});
}

float Button::getWidth() const {
    return rect.getSize().x;
}

float Button::getHeight() const {
    return rect.getSize().y;
}

void Button::setPadding(float padding) {
    setPadding(padding, padding);
}

void Button::setPadding(float topBottom, float leftRight) {
    setPadding(topBottom, leftRight, topBottom, leftRight);
}

void Button::setPadding(float top, float right, float bottom, float left) {
    paddingTop = top;
    paddingBottom = bottom;
    paddingLeft = left;
    paddingRight = right;
    resize();
}

void Button::resize() {
    rect.setSize({paddingLeft + paddingRight + textNode.getWidth(),
    paddingTop + paddingBottom + textNode.getHeight()});
    textNode.setPosition(rect.getPosition().x + paddingLeft - textNode.getLocalBounds().x,
                         rect.getPosition().y + paddingTop - textNode.getLocalBounds().y);
}