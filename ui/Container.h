//
// Created by pavel on 04.06.18.
//

#ifndef UI_CONTAINER_H
#define UI_CONTAINER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "Node.h"

namespace gui
{

class Container: public Node{
    std::vector<Node*> children;
    sf::RectangleShape rect;
    void arrangeChildren();
public:
    Container() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getHeight() const;
    virtual float getWidth() const;
    void add(Node*);
    void arrangeSelf();
    void setSize(sf::Vector2f);
    void setCenter(sf::Vector2f);
    void setCenter(float, float);
    void setBackgroundColor(const sf::Color& color);
    void resize();
    virtual sf::Vector2f getPosition();
    virtual void setPosition(float x, float y);
    virtual void setRelativePosition(float x, float y);
    sf::RectangleShape getRect();
    sf::Vector2f getCenter();
};


}


#endif //UI_CONTAINER_H
