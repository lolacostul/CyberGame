// core
#include "stdafx.hpp"

#include "Player.hpp"


// init
void Player::initVariables() {
	this->_attacking = false;
}

// constructor/destructor

Player::Player(float x, float y, sf::Texture& textureSheet) {

	// set player initial position
	this->setPosition(x, y);

	// create a hitbox component, to handle collisions
	this->createHitboxComponent(this->_sprite,
		38.f, 28.f,
		20.f, 40.f,
		sf::Color::Transparent);

	// create a movement component setting player's velocity, acceleration and deceleration
	this->createMovementComponent(300.f, 10.f, 5.f);

	// create an animation component, to animate a texture
	this->createAnimationComponent(textureSheet);

	// add animations
	this->_animationComponent->addAnimation("IDLE", 11.f, 0, 0, 7, 0, 96, 96);
	this->_animationComponent->addAnimation("MOVE", 6.f, 0, 1, 9, 1, 96, 96);
	this->_animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 14, 2, 96 * 2, 96);

	// debug
    // this->_sprite.setTexture(textureSheet);
}

// functions

// update
void Player::updateAttack() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->_attacking = true;
	}
}

void Player::updateAnimation(const float &dt) {
	// attacks
	if (this->_attacking) {
		// if the attacking animation is done, set attacking to false
		if(this->_animationComponent->play("ATTACK", dt, true)) {
			this->_attacking = false;
		}
	}

	// movements
	if (this->_movementComponent->getState(IDLE)) {
		this->_animationComponent->play("IDLE", dt);
	}
	else if (this->_movementComponent->getState(MOVING_RIGHT)) {
		if (this->_sprite.getScale().x < 0.f) {
			this->_sprite.setOrigin(0.f, 0.f);
			this->_sprite.setScale(1.f, 1.f);
		}
		this->_animationComponent->play("MOVE", dt, this->_movementComponent->getVelocity().x, this->_movementComponent->getMaxVelocity());
	}
	else if (this->_movementComponent->getState(MOVING_LEFT)) {
		if (this->_sprite.getScale().x > 0.f) {
			this->_sprite.setOrigin(96.f, 0.f);
			this->_sprite.setScale(-1.f, 1.f);
		}
		this->_animationComponent->play("MOVE", dt, this->_movementComponent->getVelocity().x, this->_movementComponent->getMaxVelocity());
	}

	else if (this->_movementComponent->getState(MOVING_UP)) {
		this->_animationComponent->play("MOVE", dt, this->_movementComponent->getVelocity().y, this->_movementComponent->getMaxVelocity());
	}
	else if (this->_movementComponent->getState(MOVING_DOWN)) {
		this->_animationComponent->play("MOVE", dt, this->_movementComponent->getVelocity().y, this->_movementComponent->getMaxVelocity());
	}
}

void Player::update(const float &dt) {
	this->_movementComponent->update(dt);

	// attacks
	this->updateAttack();
	this->updateAnimation(dt);

	this->_hitboxComponent->update();
}


// utils
std::string Player::toString() const {
	std::stringstream ss;
	ss << Character::toString() << "XP: " << this->getXP() << std::endl;
	return ss.str();
}

std::ostream& operator<<(std::ostream & out, Player const & p) {
	out << p.toString();
	return out;
}


