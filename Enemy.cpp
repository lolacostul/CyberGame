// core
#include "stdafx.hpp"

#include "Enemy.hpp"


// init
void Enemy::initVariables() {
	this->_attacking = false;
}

// constructor/destructor
Enemy::Enemy(float x, float y, sf::Texture& textureSheet, bool needsFlipping) : _needsFlipping(needsFlipping) {

	// set Enemy initial position
	this->setPosition(x, y);

	// create a hitbox component, to handle collisions
	this->createHitboxComponent(this->_sprite,
		0.f, 0.f,
		372.f, 52.f,
		sf::Color::Green);

	// create a movement component setting Enemy's velocity, acceleration and deceleration
	this->createMovementComponent(300.f, 10.f, 5.f);

	// create an animation component, to animate a texture
	this->createAnimationComponent(textureSheet);

	// add animations
	this->_animationComponent->addAnimation("IDLE", 11.f, 0, 0, 0, 0, 372, 52);
	this->_animationComponent->addAnimation("MOVE", 11.f, 0, 0, 0, 0, 372, 52);
	// this->_animationComponent->addAnimation("ATTACK", 5.f, 0, 2, 14, 2, 96 * 2, 96);

	// debug
    // this->_sprite.setTexture(textureSheet);
}

// update
void Enemy::updateAttack() {
	// this->_attacking = true;
}

void Enemy::updateAnimation(const float &dt) {
	// attacks
	// if (this->_attacking) {
	// 	// if the attacking animation is done, set attacking to false
	// 	if(this->_animationComponent->play("ATTACK", dt, true)) {
	// 		this->_attacking = false;
	// 	}
	// }

	// movements
	if (this->_movementComponent->getState(IDLE)) {
		this->_animationComponent->play("IDLE", dt);
	}
	else if (this->_movementComponent->getState(MOVING_RIGHT)) {
		if (this->_needsFlipping) {
			this->flipSprite();
		}
		
		this->_animationComponent->play("MOVE", dt, this->_movementComponent->getVelocity().x, this->_movementComponent->getMaxVelocity());
	}
	else if (this->_movementComponent->getState(MOVING_LEFT)) {
		if (this->_needsFlipping) {
			this->flipSprite();
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

void Enemy::update(const float &dt) {
	this->_movementComponent->update(dt);

	// attacks
	this->updateAttack();
	this->updateAnimation(dt);

	this->_hitboxComponent->update();
}


// utils
int Enemy::getIndex(std::vector<Enemy*> v, Enemy* e)
{
    auto it = std::find(v.begin(), v.end(), e);
 
    // if element was found
    if (it != v.end()) 
    {
        int index = it - v.begin();
		return index;
    }
    else {
		return -1;
    }
}

std::string Enemy::toString() const {
	std::stringstream ss;
	ss << Character::toString() << "Enemy" << std::endl;
	return ss.str();
}

std::ostream& operator<<(std::ostream & out, Enemy const & p) {
	out << p.toString();
	return out;
}

bool operator==(const Enemy& e1, const Enemy& e2) {
    return e1._id == e2._id;
}
