//
// Created by pavel_cpp on 6/17/18.
//

#include <iostream>
#include "TextNode.h"


TextNode::TextNode() {
    init();
}

TextNode::TextNode(std::string str) {
    init();
    text.setString(str);
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
    return text.getPosition();
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

void TextNode::setColor(sf::Color &c) {
    color = c;
    text.setFillColor(color);
}

void TextNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(text, states);
}
