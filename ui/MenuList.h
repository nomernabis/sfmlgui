//
// Created by pavel on 27.06.18.
//

#ifndef UI_MENULIST_H
#define UI_MENULIST_H

#include <functional>
#include "Container.h"
#include "elements/Button.h"
class MenuList: public Container{
    std::vector<std::string> titles;
    std::vector<std::function<void()>> actions;
    std::vector<Button*> menuItems;
    int currentIndex = 0;
    sf::Vector2f indexPosition;
    sf::RectangleShape index;
    Button* createButton(std::string title);
public:
    MenuList();
    ~MenuList();
    void add(std::string title, std::function<void()> const& lambda);
    virtual void calculateChildrenPositions();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void handleInput(sf::Event& event);
};


#endif //UI_MENULIST_H
