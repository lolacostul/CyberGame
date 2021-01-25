#include "HitboxComponent.hpp"

// constructor/destructor
HitboxComponent::HitboxComponent(
    sf::Sprite& sprite,
    float offsetX, float offsetY,
    float width, float height,
    sf::Color outlineColor)
    : _sprite(sprite), _offsetX(offsetX), _offsetY(offsetY) {

        this->_hitbox.setPosition(this->_sprite.getPosition().x + offsetX, this->_sprite.getPosition().y + offsetY);
        this->_hitbox.setSize(sf::Vector2f(width, height));
        this->_hitbox.setFillColor(sf::Color::Transparent);
        this->_hitbox.setOutlineThickness(1.f);
        this->_hitbox.setOutlineColor(outlineColor);

}

HitboxComponent::~HitboxComponent() {

}

// accessors/getters
const sf::Vector2f &HitboxComponent::getPosition() const {
    return this->_hitbox.getPosition();
}

const sf::FloatRect HitboxComponent::getGlobalBounds() const {
	return this->_hitbox.getGlobalBounds();
}

// functions
bool HitboxComponent::checkIntersect(const sf::FloatRect& frect) {
    return this->_hitbox.getGlobalBounds().intersects(frect);
}


// update

void HitboxComponent::update() {
    this->_hitbox.setPosition(
        this->_sprite.getPosition().x + this->_offsetX,
        this->_sprite.getPosition().y + this->_offsetY);
}

// render

void HitboxComponent::render(sf::RenderTarget& target) {
    target.draw(this->_hitbox);
}