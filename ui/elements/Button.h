//
// Created by pavel_cpp on 18.06.18.
//

#ifndef UI_BUTTON_H
#define UI_BUTTON_H


#include <SFML/Graphics/RectangleShape.hpp>
#include "../Node.h"
#include "TextNode.h"

class Button: public Node{
public:
    enum class Alignment{
        LEFT, CENTER, RIGHT
    };
    bool isFixedSize = false;
    Alignment alignment = Alignment::CENTER;
    Button(std::string text = "");
    virtual sf::Vector2f getPosition();
    virtual void setPosition(float x, float y);
    virtual void setRelativePosition(float x, float y);
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    virtual float getWidth() const;
    virtual float getHeight() const;
    void setPadding(float padding);
    void setPadding(float topBottom, float leftRight);
    void setPadding(float top, float right, float bottom, float left);
    void setText(std::string text);
    void setBackgroundColor(sf::Color);
    void setTextColor(sf::Color);
    void setAlignment(Alignment alignment);
    void setFixedSize(bool isFixedSize);

    //
private:
    //
    TextNode textNode;
    sf::RectangleShape rect;
    float paddingTop = 0;
    float paddingBottom = 0;
    float paddingLeft = 0;
    float paddingRight = 0;
    void resize();
};


#endif //UI_BUTTON_H
