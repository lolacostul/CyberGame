// core
#include "stdafx.hpp"

#include "Character.hpp"

// init
void Character::initVariables() {
	this->_hitboxComponent = NULL;
	this->_movementComponent = NULL;
	this->_animationComponent = NULL;
}


Character::Character() : _isDead(1) {
	this->initVariables();
	this->set_race(this->_raceVect[0]);
}

Character::~Character() {
	delete this->_hitboxComponent;
	delete this->_movementComponent;
	delete this->_animationComponent;
}

// accessors/getters
const sf::Vector2f& Character::getPosition() const {
	return this->_sprite.getPosition();
}

const sf::FloatRect Character::getGlobalBounds() const {
	if (this->_hitboxComponent)
		return this->_hitboxComponent->getGlobalBounds();

	return this->_sprite.getGlobalBounds();
}

// functions
void Character::sufferDamages(int nbDamages) {
	this->_hp -= nbDamages;
	if (this->get_hp() <= 0) {
		this->set_hp(0);
		this->set_isDead(0);
	}
}

void Character::attack(Character &cible, int damages) {
	cible.sufferDamages(damages); // ???
}

void Character::heal(int nbHeal) {
	this->_hp += nbHeal;
	if (this->get_hp() > 100) {	// max 100 HP
		this->set_hp(100);
	}
}

void Character::isAlive() {
	if (this->get_hp() > 0) {
		this->set_isDead(true);
	} else {
		this->set_isDead(false);
	}
}

void Character::setTexture(sf::Texture& texture) {
	this->_sprite.setTexture(texture);
}

void Character::setPosition(float x, float y) {
	this->_sprite.setPosition(x, y);
}

void Character::flipSprite() {
	if (this->_sprite.getScale().x < 0.f) {
		this->_sprite.setOrigin(0.f, 0.f);
		this->_sprite.setScale(1.f, 1.f);
	}
	else if (this->_sprite.getScale().x > 0.f) {
		this->_sprite.setOrigin(96.f, 0.f);
		this->_sprite.setScale(-1.f, 1.f);
	}
}

// components
void Character::createHitboxComponent(sf::Sprite &sprite,
		const float offsetX, const float offsetY,
		float width, float height,
		sf::Color outlineColor) {
	/* Create a hitbox */
	this->_hitboxComponent = new HitboxComponent(
		sprite,
		offsetX, offsetY,
		width, height,
		outlineColor);
}

void Character::createMovementComponent(float maxVelocity, const float acceleration, const float deceleration) {
	/* Create a movement */
	this->_movementComponent = new MovementComponent(this->_sprite, maxVelocity, acceleration, deceleration);
}

void Character::createAnimationComponent(sf::Texture& textureSheet) {
	/* Create an animation */
	this->_animationComponent = new AnimationComponent(this->_sprite, textureSheet);
}

// actions
void Character::move(const float dir_x, const float dir_y, const float& dt) {
	if (this->_movementComponent) {
		this->_movementComponent->move(dir_x, dir_y, dt);
	}
}

// update
void Character::update(const float &dt) {
	if (this->_movementComponent) {
		this->_movementComponent->update(dt);
	}
}

// rendering
void Character::render(sf::RenderTarget& target) {
		target.draw(this->_sprite);

		if (this->_hitboxComponent) {
			this->_hitboxComponent->render(target);
		}
}

// utils
std::string Character::toString() const {
	std::stringstream ss;
	ss << "Name: " << this->get_characterClass() << "\nRace: " << this->get_race()
		<< "\nHP: " << this->get_hp() << "\nMana: " << this->get_mana() << std::endl;
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Character const & c) {
	out << c.toString();
	return out;
}
