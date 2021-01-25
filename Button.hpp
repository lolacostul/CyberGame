#ifndef BUTTON_H
#define BUTTON_H

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVERED, BTN_ACTIVE};

class Button {
	private:
        short unsigned _buttonState;
        bool _pressed;
        bool _hovered;

        sf::RectangleShape _shape;
        sf::Font* _font;
        sf::Text _text;

        sf::Color textIdleColor;
        sf::Color textHoverColor;
        sf::Color textActiveColor;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

	public:
        Button(
            float x, float y, float width, float height,
            sf::Font* font, std::string text, unsigned fontSize,
            sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
            sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor
        );
        ~Button();

        // accessors
        const bool isPressed() const;

        // functions

        // update
        void update(const sf::Vector2f mousePos);

        // render
        void render(sf::RenderTarget& target);


};

#endif