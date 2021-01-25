#ifndef __MOVEMENTCOMPONENT_HPP__
#define __MOVEMENTCOMPONENT_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum movementStates {IDLE = 0, MOVING, MOVING_LEFT, MOVING_RIGHT, MOVING_UP, MOVING_DOWN, ATTACKING};

class MovementComponent {
    private:
        sf::Sprite& _sprite;

        float _maxVelocity;
        float _acceleration;
        float _deceleration;

        sf::Vector2f _velocity;

        // init

    public:
        MovementComponent(sf::Sprite& sprite, float maxVelocity,
            float acceleration, float deceleration);
        virtual ~MovementComponent();

        // accessors/getters
        const sf::Vector2f& getVelocity() const;
        const float& getMaxVelocity() const;

        // functions
        const bool getState(const short unsigned state) const; 
        void move(const float x, const float y, const float &dt);

        // update
        void update(const float& dt);

};


#endif