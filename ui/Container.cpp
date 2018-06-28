//
// Created by pavel on 04.06.18.
//
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Container.h"
#include "Utils.h"


void Container::setSizeMode(Container::SizeMode mode) {
    sizeMode = mode;
}

void Container::setWindow(sf::RenderWindow *window) {
    this->window = window;
}

void Container::setCenterVertical(bool isCV) {
    this->isCenterVertical = isCV;
    resize();
    calculateChildrenPositions();
}

void Container::setCenterHorizontal(bool isCH) {
    this->isCenterHorizontal = isCH;
    resize();
    calculateChildrenPositions();
}

void Container::setCenterInParent(bool isCP) {
    isCenterHorizontal = isCP;
    isCenterVertical = isCP;
    resize();
    calculateChildrenPositions();
}

void Container::setTopInParent(bool isTop) {
    this->isTopInParent = isTop;
    resize();
    calculateChildrenPositions();
}

void Container::setBottomInparent(bool isBottom) {
    this->isBottomInParent = isBottom;
    resize();
    calculateChildrenPositions();
}

void Container::setAlignment(Container::Alignment hAlignment, Container::Alignment vAlignment) {
    this->vAlignment = vAlignment;
    this->hAlignment = hAlignment;
    resize();
    calculateChildrenPositions();
}

sf::Vector2f Container::getPosition() {
    return rect.getPosition();
}

void Container::setRelativePosition(float x, float y) {
    sf::Vector2f position = getParentNode()->getPosition();
    setPosition(x + position.x, y + position.y);
}

void Container::setPosition(float x, float y) {
    rect.setPosition(x, y);
}

float Container::getHeight() const {
    return rect.getSize().y;
}

float Container::getWidth() const {
    return rect.getSize().x;
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(rect, states);
    for (Node *node:children) {
        node->draw(target, states);
    }
}

void Container::add(Node *child) {
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

void Container::setPadding(float padding) {
    setPadding(padding, padding);
}

void Container::setPadding(float top_bottom, float left_right) {
    setPadding(top_bottom, left_right, top_bottom, left_right);
}

void Container::setPadding(float top, float right, float bottom, float left) {
    paddingTop = top;
    paddingRight = right;
    paddingBottom = bottom;
    paddingLeft = left;
    resize();
}

void Container::calculateChildrenPositions() {
    int offset = 0;


    for (int i = 0; i < children.size(); ++i) {
        Node *child = children.at(i);

        float x = 0;
        if (hAlignment == Alignment::CENTER) {
            x = (getWidth() - child->getWidth()) / 2;
        }
        if(child->getMarginTop() != 0){
            offset -= childSpacing;
            offset += child->getMarginBottom();
        }
        child->setRelativePosition(x, offset);
        if(child->getMarginBottom() != 0){
            offset -= childSpacing;
            offset += child->getMarginBottom();
        }
        offset += child->getHeight() + childSpacing;
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

void Container::resize() {
    float height = 0, width = 0;
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
        sf::Vector2f windowCenter = Utils::getCenterOf(window);
        setPosition(getPosition().x, windowCenter.y - rect.getSize().y / 2);
    }
    if (isCenterHorizontal) {
        sf::Vector2f windowCenter = Utils::getCenterOf(window);
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

void Container::setChildSpacing(float spacing) {
    this->childSpacing = spacing;
}

bool Container::isContainer(Node *node) {
    return dynamic_cast<Container*>(node) != nullptr;
}

void Container::invalidate() {
}

void Container::setSize(sf::Vector2f size) {
    rect.setSize(size);
}

void Container::setSize(float x, float y) {
    rect.setSize({x, y});
}

sf::RectangleShape Container::getRect() {
    return rect;
}

sf::Vector2f Container::getCenter() {
    return {rect.getPosition() + rect.getSize() / 2.f};
}

void Container::setBackgroundColor(const sf::Color &color) {
    rect.setFillColor(color);
}
