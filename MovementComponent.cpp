// core
#include "stdafx.hpp"

#include "MovementComponent.hpp"

// constructor/destructor
MovementComponent::MovementComponent(sf::Sprite& sprite,
    float maxVelocity, float acceleration, float deceleration)
    : _sprite(sprite), _maxVelocity(maxVelocity), _acceleration(acceleration), _deceleration(deceleration) {
}

MovementComponent::~MovementComponent() {

}

// accessors/getters

const sf::Vector2f &MovementComponent::getVelocity() const {
    return this->_velocity;
}

const float &MovementComponent::getMaxVelocity() const {
    return this->_maxVelocity;
}


// functions
const bool MovementComponent::getState(unsigned short state) const {
    switch (state) {
    case IDLE:
        if (this->_velocity.x == 0.f && this->_velocity.y == 0.f)
            return true;
        break;
    case MOVING:
        if (this->_velocity.x != 0.f || this->_velocity.y != 0.f)
            return true;
        break;
    case MOVING_LEFT:
        if (this->_velocity.x < 0.f)
            return true;
        break;
    case MOVING_RIGHT:
        if (this->_velocity.x > 0.f)
            return true;
        break;
    case MOVING_UP:
        if (this->_velocity.y < 0.f)
            return true;
        break;
    case MOVING_DOWN:
        if (this->_velocity.y > 0.f)
            return true;
        break;
    case ATTACKING:
        break;
    }
    
    return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float &dt) {
    /*
    Accelerates a sprite.
    Handles sprite movement.
    */

    this->_velocity.x += this->_acceleration * dir_x;
    this->_velocity.y += this->_acceleration * dir_y;
}

// update
void MovementComponent::update(const float &dt) {
    /*
    Decelerates a sprite and controls max velocity.
    Handles sprite movement.
    */

    if (this->_velocity.x > 0.f) { // moving right
        // max velocity check
        if (this->_velocity.x > this->_maxVelocity) {
            this->_velocity.x = this->_maxVelocity;
        }

        // deceleration
        this->_velocity.x -= this->_deceleration;
        if (this->_velocity.x < 0.f) {
            this->_velocity.x = 0.f;
        }
    }
    else if (this->_velocity.x < 0.f) { // moving left
        // max velocity check
        if (this->_velocity.x < -this->_maxVelocity) {
            this->_velocity.x = -this->_maxVelocity;
        }
    
        // deceleration
        this->_velocity.x += this->_deceleration;
        if (this->_velocity.x > 0.f) {
            this->_velocity.x = 0.f;
        }
    }

    if (this->_velocity.y > 0.f) { // moving down
        // max velocity check
        if (this->_velocity.y > this->_maxVelocity) {
            this->_velocity.y = this->_maxVelocity;
        }

        // deceleration
        this->_velocity.y -= this->_deceleration;
        if (this->_velocity.y < 0.f) {
            this->_velocity.y = 0.f;
        }
    }
    else if (this->_velocity.y < 0.f) { // moving up
        // max velocity check
        if (this->_velocity.y < -this->_maxVelocity) {
            this->_velocity.y = -this->_maxVelocity;
        }
    
        // deceleration
        this->_velocity.y += this->_deceleration;
        if (this->_velocity.y > 0.f) {
            this->_velocity.y = 0.f;
        }
    }

    this->_sprite.move(this->_velocity * dt);
}
