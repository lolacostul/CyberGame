// core
#include "stdafx.hpp"

#include "AnimationComponent.hpp"

// constructor/destructor
AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet)
    : _sprite(sprite), _textureSheet(textureSheet), _lastAnimation(NULL), _priorityAnimation(NULL) {

}

AnimationComponent::~AnimationComponent() {
    for (auto &i : this->_animations) {
        delete i.second;
    }
    
}

// accessors/getters
const bool& AnimationComponent::isDone(const std::string key) {
    return this->_animations[key]->isDone();
}

// functions

void AnimationComponent::addAnimation(
    const std::string key,
    float animationTimer,
    int startFrameX, int startFrameY, int framesX, int framesY,
    int width, int height) {

    this->_animations[key] = new Animation(
        this->_sprite, this->_textureSheet,
        animationTimer,
        startFrameX, startFrameY, framesX, framesY,
        width, height);
}


// update
const bool& AnimationComponent::play(const std::string key, const float &dt, const bool priority) {    
    if (this->_priorityAnimation) { // if there is a priority animation
        if (this->_priorityAnimation == this->_animations[key]) {
            if (this->_lastAnimation != this->_animations[key]) {
                if (this->_lastAnimation == NULL) {
                    this->_lastAnimation = this->_animations[key];
                }
                else {
                    this->_lastAnimation->reset();
                    this->_lastAnimation = this->_animations[key];
                }
            }
            // if the priority animation is done, remove it
            if (this->_animations[key]->play(dt)) {
                this->_priorityAnimation = NULL;
            }
        }
    }
    else { // play animation if no priority animation
        // if this is a priority animation, set it
        if (priority) {
            this->_priorityAnimation = this->_animations[key];
        }
        if (this->_lastAnimation != this->_animations[key]) {
            if (this->_lastAnimation == NULL) {
                this->_lastAnimation = this->_animations[key];
            }
            else {
                this->_lastAnimation->reset();
                this->_lastAnimation = this->_animations[key];
            }
        }
        this->_animations[key]->play(dt);
    }
    return this->_animations[key]->isDone();
}

const bool& AnimationComponent::play(const std::string key, const float &dt,
    const float& modifier, const float modifierMax,
    const bool priority) {

    float modPercentage = abs(modifier / modifierMax);

    if (this->_priorityAnimation) { // if there is a priority animation
        if (this->_priorityAnimation == this->_animations[key]) {
            if (this->_lastAnimation != this->_animations[key]) {
                if (this->_lastAnimation == NULL) {
                    this->_lastAnimation = this->_animations[key];
                }
                // reset the last animation before playing another
                else {
                    this->_lastAnimation->reset();
                    this->_lastAnimation = this->_animations[key];
                }
            }
        this->_animations[key]->play(dt, modPercentage);
        }
    }
    else { // play animation if no priority animation
        // if this is a priority animation, set it
        if (priority) {
            this->_priorityAnimation = this->_animations[key];
        }
        if (this->_lastAnimation != this->_animations[key]) {
            if (this->_lastAnimation == NULL) {
                this->_lastAnimation = this->_animations[key];
            }
            // reset the last animation before playing another
            else {
                this->_lastAnimation->reset();
                this->_lastAnimation = this->_animations[key];
            }
        }
        // if the priority animation is done, remove it
        if (this->_animations[key]->play(dt, modPercentage)) {
            this->_priorityAnimation = NULL;
        }
    }
    return this->_animations[key]->isDone();
}