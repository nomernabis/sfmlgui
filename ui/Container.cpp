//
// Created by pavel on 04.06.18.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Container.h"
#include "Utils.h"


void gui::Container::setSizeMode(gui::Container::SizeMode mode) {
    sizeMode = mode;
}

void gui::Container::setWindow(sf::RenderWindow *window) {
    this->window = window;
}

void gui::Container::setCenterVertical(bool isCV) {
    this->isCenterVertical = isCV;
    resize();
    calculateChildrenPositions();
}

void gui::Container::setCenterHorizontal(bool isCH) {
    this->isCenterHorizontal = isCH;
    resize();
    calculateChildrenPositions();
}

void gui::Container::setCenterInParent(bool isCP) {
    isCenterHorizontal = isCP;
    isCenterVertical = isCP;
    resize();
    calculateChildrenPositions();
}

void gui::Container::setTopInParent(bool isTop) {
    this->isTopInParent = isTop;
    resize();
    calculateChildrenPositions();
}

void gui::Container::setBottomInparent(bool isBottom) {
    this->isBottomInParent = isBottom;
    resize();
    calculateChildrenPositions();
}

void gui::Container::setAlignment(gui::Container::Alignment hAlignment, gui::Container::Alignment vAlignment) {
    this->vAlignment = vAlignment;
    this->hAlignment = hAlignment;
    resize();
    calculateChildrenPositions();
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

float gui::Container::getHeight() const {
    return rect.getSize().y;
}

float gui::Container::getWidth() const {
    return rect.getSize().x;
}

void gui::Container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
    for (Node *node:children) {
        node->draw(target, states);
    }
}

void gui::Container::add(Node *child) {
    children.push_back(child);
    child->setParentNode(this);

    sf::Vector2f prevSize = rect.getSize();

    if (sizeMode == SizeMode::WRAP_CONTENT) {
        resize();

        sf::Vector2f diffSize = rect.getSize() - prevSize;

        float newX = getPosition().x;
        float newY = getPosition().y;

        setPosition(newX, newY);
    }

    calculateChildrenPositions();
}

void gui::Container::setPadding(float padding) {
    setPadding(padding, padding);
}

void gui::Container::setPadding(float top_bottom, float left_right) {
    setPadding(top_bottom, left_right, top_bottom, left_right);
}

void gui::Container::setPadding(float top, float right, float bottom, float left) {
    paddingTop = top;
    paddingRight = right;
    paddingBottom = bottom;
    paddingLeft = left;
    resize();
}

void gui::Container::calculateChildrenPositions() {
    int padding = 10;
    int offset = padding;


    for (int i = 0; i < children.size(); ++i) {
        Node *child = children.at(i);

        float x = padding;
        if (hAlignment == Alignment::CENTER) {
            x = (getWidth() - child->getWidth()) / 2;
        }
        if(child->getMarginTop() != 0){
            offset -= padding;
            offset += child->getMarginBottom();
        }
        child->setRelativePosition(x, offset);
        if(child->getMarginBottom() != 0){
            offset -= padding;
            offset += child->getMarginBottom();
        }
        offset += child->getHeight() + padding;
    }

    if (vAlignment == Alignment::CENTER) {
        int height = offset;
        float yOffset = (getHeight() - height) / 2;
        for (int i = 0; i < children.size(); ++i) {
            Node *child = children.at(i);
            child->setPosition(child->getPosition().x, child->getPosition().y + yOffset);

            Container* container = dynamic_cast<Container*>(child);
            if(container != nullptr){
                container->calculateChildrenPositions();
            }
        }
    }
}

void gui::Container::resize() {
    float height = 0, width = 0;
    int offset = 10;
    for (Node *child: children) {
        if(child->getMarginTop() != 0){
            height += child->getMarginTop();
        }
        if(child->getMarginBottom() != 0){
            height += child->getMarginBottom();
        }
        if(child->getMarginTop() == 0 && child->getMarginBottom() == 0){
            height += childSpacing;
        }

        height += child->getHeight();
        if (child->getWidth() > width) {
            width = child->getWidth();
        }
    }
    height += paddingBottom;
    width += paddingLeft + paddingRight;
    if(sizeMode == SizeMode::WRAP_CONTENT){
        setSize({width, height});
    }

    if (isCenterVertical) {
        sf::Vector2f windowCenter = gui::Utils::getCenterOf(window);
        setPosition(getPosition().x, windowCenter.y - rect.getSize().y / 2);
    }
    if (isCenterHorizontal) {
        sf::Vector2f windowCenter = gui::Utils::getCenterOf(window);
        setPosition(windowCenter.x - getWidth() / 2, getPosition().y);
    }

    if (isBottomInParent) {
        setPosition(getPosition().x, window->getSize().y - rect.getSize().y);
    }

    for(Node* child: children){
        Container* container = dynamic_cast<Container*>(child);
        if(container != nullptr){
            container->resize();
        }
    }

}

bool gui::Container::isContainer(Node *node) {
    return dynamic_cast<Container*>(node) != nullptr;
}

void gui::Container::invalidate() {
}

void gui::Container::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

void gui::Container::setSize(float x, float y) {
    rect.setSize({x, y});
}

sf::RectangleShape gui::Container::getRect() {
    return rect;
}

sf::Vector2f gui::Container::getCenter() {
    return {rect.getPosition() + rect.getSize() / 2.f};
}

void gui::Container::setBackgroundColor(const sf::Color &color) {
    rect.setFillColor(color);
}
