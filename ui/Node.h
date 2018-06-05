//
// Created by pavel on 04.06.18.
//

#ifndef UI_NODE_H
#define UI_NODE_H


#include <SFML/Graphics/Drawable.hpp>

class Node: public sf::Drawable{
    Node* parent;
public:
    Node* getParentNode() const;
    void setParentNode(Node* parent);
    virtual float getWidth() const = 0;
    virtual float getHeight() const = 0;
    virtual void setPosition(float x, float y){};
    virtual void setRelativePosition(float x, float y){};
    virtual sf::Vector2f getPosition(){};
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {};
    virtual ~Node() {};
};


#endif //UI_NODE_H
