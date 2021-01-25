#ifndef __HITBOXCOMPONENT_HPP__
#define __HITBOXCOMPONENT_HPP__

#include <iostream>
#include <ctime>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class HitboxComponent {
    private:
        sf::Sprite& _sprite;
        sf::RectangleShape _hitbox;
        float _offsetX;
        float _offsetY;

    public:
        // constructor/destructor
        HitboxComponent(
            sf::Sprite& sprite,
            float offsetX, float offsetY,
            float width, float height,
            sf::Color outlineColor);
        virtual ~HitboxComponent();

        // accessors/getters
        const sf::Vector2f & getPosition() const;
        const sf::FloatRect getGlobalBounds() const;

        // functions
        bool checkIntersect(const sf::FloatRect& frect);

        // update
        void update();

        // render
        void render(sf::RenderTarget& target);
};

#endif