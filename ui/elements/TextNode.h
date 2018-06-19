//
// Created by pavel_cpp on 6/17/18.
//

#ifndef UI_TEXTVIEW_H
#define UI_TEXTVIEW_H


#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "../Node.h"

class TextNode: public Node {
    const std::string FONTS_PATH = "resources/fonts/";

    sf::Text text;
    sf::Font font;
    sf::Color color = sf::Color::Black;
    void init();
public:
    TextNode();
    TextNode(std::string);
    void setText(std::string);
    void setFont(std::string);
    void setColor(sf::Color&);
    virtual float getWidth() const;
    virtual float getHeight() const;
    virtual void setPosition(float, float);
    virtual sf::Vector2f getPosition();
    virtual void setRelativePosition(float, float);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //UI_TEXTVIEW_H
