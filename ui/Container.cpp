//
// Created by pavel on 04.06.18.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Container.h"

void gui::Container::arrangeSelf() {

}

sf::Vector2f gui::Container::getPosition() {
    return rect.getPosition();
}

void gui::Container::setRelativePosition(float x, float y) {
    sf::Vector2f position = getParentNode()->getPosition();
    setPosition(x + position.x, y + position.y);
}

void gui::Container::setPosition(float x, float y) {
    rect.setPosition(x, y);
}

void gui::Container::arrangeChildren() {
    int padding = 10;
    int offset = padding;
    for(int i=0; i < children.size(); ++i){
        Node* child = children.at(i);
        child->setRelativePosition(padding, offset);
        offset += child->getHeight() + padding;
    }
}

float gui::Container::getHeight() const {
    return rect.getSize().y;
}

float gui::Container::getWidth() const {
    return rect.getSize().x;
}

void gui::Container::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(rect, states);
    for(Node* node:children){
        node->draw(target, states);
    }
}

void gui::Container::add(Node* child) {
    children.push_back(child);
    child->setParentNode(this);
    sf::Vector2f size = rect.getSize();
    resize();
    float diffY = rect.getSize().y - size.y;

    setPosition(getPosition().x, getPosition().y - diffY / 2);
    arrangeChildren();
}

void gui::Container::resize() {
    float height = 0, width = 0;
    int offset = 10;
    for(Node* child: children){
        height += offset + child->getHeight();
        if(child->getWidth() > width){
            width = child->getWidth();
        }
    }
    height += offset;
    width += 2 * offset;
    setSize({width, height});
}

void gui::Container::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

sf::RectangleShape gui::Container::getRect() {
    return rect;
}

void gui::Container::setCenter(sf::Vector2f center) {
    const sf::Vector2f& size = rect.getSize();
    rect.setPosition(center.x - size.x / 2,  center.y - size.y / 2);
}

void gui::Container::setCenter(float x, float y) {
    setCenter({x, y});
}

void gui::Container::setBackgroundColor(const sf::Color& color) {
    rect.setFillColor(color);
}

sf::Vector2f gui::Container::getCenter() {
    const sf::Vector2f& pos = rect.getPosition();
    const sf::Vector2f& size = rect.getSize();
    return {pos.x + size.x / 2, pos.y + size.y / 2};
}