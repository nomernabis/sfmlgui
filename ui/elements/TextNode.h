//
// Created by pavel_cpp on 6/17/18.
//

#ifndef UI_TEXTVIEW_H
#define UI_TEXTVIEW_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include "../Node.h"

class TextNode: public Node {
    const std::string FONTS_PATH = "resources/fonts/";
    sf::RenderWindow* window;
    sf::Text text;
    sf::Font font;
    sf::Color color = sf::Color::Black;
    bool isCenterInParent = false;
    bool isCenterHorizontal = false;
    void init();
public:
    TextNode();
    TextNode(std::string);
    void setText(std::string);
    void setFont(std::string);
    void setTextColor(const sf::Color&);
    void setFontSize(int size);
    virtual float getWidth() const;
    virtual float getHeight() const;
    virtual void setPosition(float, float);
    virtual sf::Vector2f getPosition();
    virtual void setRelativePosition(float, float);
    void setCenterInParent(bool value);
    void setCenterHorizontal(bool value);
    void setWindow(sf::RenderWindow* window);
    virtual void setMarginTop(float marginTop);
    sf::Vector2f getLocalBounds();
    void setPosition(sf::Vector2f pos);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //UI_TEXTVIEW_H
