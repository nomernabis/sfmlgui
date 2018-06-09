//
// Created by pavel on 04.06.18.
//

#ifndef UI_UTILS_H
#define UI_UTILS_H


#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace gui{
    class Utils {
    public:
        static sf::Vector2f getCenterOf(sf::RenderWindow&);
        static float getBottomOf(sf::RenderTarget&);
    };
}


#endif //UI_UTILS_H
