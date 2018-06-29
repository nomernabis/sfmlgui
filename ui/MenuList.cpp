//
// Created by pavel on 27.06.18.
//

#include "MenuList.h"

MenuList::MenuList() {
    index.setFillColor(sf::Color::White);
    index.setSize({10, 10});
}

MenuList::~MenuList() {
    for(Button* button: menuItems){
        delete button;
    }
}
void MenuList::add(std::string title) {
    titles.push_back(title);
    Button* button = createButton(title);
    menuItems.push_back(button);
    Container::add(button);
}

Button* MenuList::createButton(std::string title) {
    Button* button = new Button;
    button->setText(title);
    button->setTextColor(sf::Color::White);
    button->setBackgroundColor(sf::Color::Black);
    return button;
}

void MenuList::calculateChildrenPositions() {
    Container::calculateChildrenPositions();
    Button* button;
    if(!menuItems.empty()){
        button = menuItems.at(currentIndex);
        float left = button->getPosition().x;
        float centerY = button->getPosition().y + button->getHeight() / 2;
        index.setPosition(left - 20, centerY - 5);
    }

}

void MenuList::handleInput(sf::Event &event) {
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Down){
            if(!menuItems.empty()){
                currentIndex++;
                currentIndex = currentIndex % menuItems.size();
                calculateChildrenPositions();
            }
        }
        if(event.key.code == sf::Keyboard::Up){
           if(!menuItems.empty()){
               currentIndex--;
               if(currentIndex < 0){
                   currentIndex = menuItems.size() - 1;
               }
               calculateChildrenPositions();
           }
        }
    }
}

void MenuList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    Container::draw(target, states);
    target.draw(index, states);
}
