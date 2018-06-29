//
// Created by pavel_cpp on 6/17/18.
//

#include <iostream>
#include "TextNode.h"
#include "../Utils.h"


TextNode::TextNode() {
    init();
}

void TextNode::setWindow(sf::RenderWindow* window) {
    this->window = window;
}

TextNode::TextNode(std::string str) {
    init();
    text.setString(str);
}

void TextNode::setMarginTop(float marginTop) {
    Node::setMarginTop(marginTop);
    text.setPosition(getPosition().x, marginTop);
}

void TextNode::init() {
    if (!font.loadFromFile(FONTS_PATH + "Atarian.ttf")) {
        std::cout << "Could not load from file\n";
    }
    text.setFont(font);
    text.setFillColor(color);
}

float TextNode::getWidth() const {
    return text.getGlobalBounds().width;
}

float TextNode::getHeight() const {
    return text.getGlobalBounds().height;
}

void TextNode::setPosition(float x, float y) {
    text.setPosition(x, y);
}

sf::Vector2f TextNode::getPosition() {
    return text.getPosition() ;
}

void TextNode::setRelativePosition(float x, float y) {
    text.setPosition(getParentNode()->getPosition().x + x, getParentNode()->getPosition().y + y);
}

void TextNode::setText(std::string str) {
    text.setString(str);
}

void TextNode::setFont(std::string fontName) {
    if (!font.loadFromFile(FONTS_PATH + fontName + ".ttf")) {
        std::cout << "Could not load from file\n";
    }
    text.setFont(font);
}

void TextNode::setCenterHorizontal(bool value) {
    this->isCenterHorizontal = value;
    float centerX = Utils::getCenterOf(window).x;
    setPosition(centerX - getWidth() / 2, getPosition().y);
}

void TextNode::setFontSize(int size) {
    text.setCharacterSize(size);
}

void TextNode::setTextColor(const sf::Color& c) {
    color = c;
    text.setFillColor(color);
}

void TextNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text, states);
}

void TextNode::setPosition(sf::Vector2f pos) {
    text.setPosition(pos);
}

sf::Vector2f TextNode::getLocalBounds() {
    return {text.getLocalBounds().left, text.getLocalBounds().top};
}

void TextNode::setCenterInParent(bool value) {
    isCenterInParent = value;
    sf::Vector2f center = Utils::getCenterOf(window);
    setPosition(center.x - getWidth() / 2, center.y  - getHeight() / 2);
}