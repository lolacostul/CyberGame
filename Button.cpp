#include "Button.hpp"


/*----- constructor/destructor -----*/
Button::Button(float x, float y, float width, float height,
    sf::Font* font, std::string text, unsigned fontSize,
    sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {

    this->_buttonState = BTN_IDLE;

    this->_shape.setPosition(sf::Vector2f(x, y));
    this->_shape.setSize(sf::Vector2f(width, height));
    this->_shape.setFillColor(this->idleColor);

    this->_font = font;
    this->_text.setFont(*this->_font);
    this->_text.setString(text);
    this->_text.setFillColor(textIdleColor);
    this->_text.setCharacterSize(fontSize);
    this->_text.setPosition(
        this->_shape.getPosition().x + (this->_shape.getGlobalBounds().width / 2.f) - this->_text.getGlobalBounds().width / 2.f,
        this->_shape.getPosition().y + (this->_shape.getGlobalBounds().height / 2.f) - this->_text.getGlobalBounds().height / 2.f
    );

    this->textIdleColor = textIdleColor;
    this->textHoverColor = textHoverColor;
    this->textActiveColor = textActiveColor;

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

}

Button::~Button() {

}

/*----- accessors -----*/
const bool Button::isPressed() const {
    if (this->_buttonState == BTN_ACTIVE) {
        return true;
    }
    return false;
}


/*----- update -----*/
void Button::update(const sf::Vector2f mousePos) {
    // update the state for hovered and pressed

    this->_buttonState = BTN_IDLE;

    // hovered
    if (this->_shape.getGlobalBounds().contains(mousePos)) {
        this->_buttonState = BTN_HOVERED;

        //pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->_buttonState = BTN_ACTIVE;
        }
    }

    switch (this->_buttonState) {
    case BTN_IDLE:
        this->_shape.setFillColor(this->idleColor);
        this->_text.setFillColor(this->textIdleColor);
        break;
    case BTN_HOVERED:
        this->_shape.setFillColor(this->hoverColor);
        this->_text.setFillColor(this->textHoverColor);
        break;
    case BTN_ACTIVE:
        this->_shape.setFillColor(this->activeColor);
        this->_text.setFillColor(this->textActiveColor);
        break;
    
    default:
        this->_shape.setFillColor(sf::Color::Red);
        this->_text.setFillColor(sf::Color::Blue);
        break;
    }
}

/*----- render -----*/
void Button::render(sf::RenderTarget& target) {
    target.draw(this->_shape);
    target.draw(this->_text);

}