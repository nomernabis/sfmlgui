//
// Created by pavel_cpp on 18.06.18.
//

#ifndef UI_BUTTON_H
#define UI_BUTTON_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../Node.h"
#include "TextNode.h"

class Button: public Node{
    TextNode textNode;
    sf::RectangleShape rect;
public:
    Button(std::string text = "");
    virtual void setPosition(float x, float y);
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    virtual float getWidth() const;
    virtual float getHeight() const;
};


#endif //UI_BUTTON_H
