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
public:
    enum class Alignment{
        TOP, DOWN, LEFT, RIGHT, CENTER, BOTTOM
    };
    enum class SizeMode{
        FILL_PARENT,
        WRAP_CONTENT,
        FIXED
    };

    Container() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual float getHeight() const;
    virtual float getWidth() const;
    void add(Node*);
    void setSize(sf::Vector2f);
    void setSize(float, float);
    void setBackgroundColor(const sf::Color& color);
    void resize();
    virtual sf::Vector2f getPosition();
    virtual void setPosition(float x, float y);
    virtual void setRelativePosition(float x, float y);
    sf::RectangleShape getRect();
    sf::Vector2f getCenter();
    void setAlignment(Alignment vAlignment, Alignment hAlignment);
    void setWindow(sf::RenderWindow* window);
    void setSizeMode(SizeMode mode);
    void setCenterVertical(bool);
    void setCenterHorizontal(bool);
    void setCenterInParent(bool);
    void setBottomInparent(bool);
    void setTopInParent(bool);
    void invalidate();
    bool isContainer(Node* node);
    void setPadding(float padding);
    void setPadding(float top_bottom, float left_right);
    void setPadding(float top, float right, float bottom, float left);
private:
    sf::RenderWindow* window;
    Alignment vAlignment = Alignment::TOP;
    Alignment hAlignment = Alignment::LEFT;
    SizeMode sizeMode = SizeMode::WRAP_CONTENT;
    std::vector<Node*> children;
    sf::RectangleShape rect;
    //relative to parent
    bool isCenterVertical = false;
    bool isCenterHorizontal = false;
    bool isTopInParent = false;
    bool isBottomInParent = false;
    void calculateChildrenPositions();

    float paddingTop = 0;
    float paddingBottom = 0;
    float paddingLeft = 0;
    float paddingRight = 0;

    float childSpacing = 10;

};


}


#endif //UI_CONTAINER_H
