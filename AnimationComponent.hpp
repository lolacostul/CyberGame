#ifndef __ANIMATIONCOMPONENT_HPP__
#define __ANIMATIONCOMPONENT_HPP__

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class AnimationComponent {
    private:
        class Animation {
            public:
                // variables
                sf::Sprite& _sprite;
                sf::Texture& _textureSheet;
                float _animationTimer;
                float _timer;
                bool _done;
                unsigned _width;
                unsigned _height;
                sf::IntRect _startRect;
                sf::IntRect _curRect;
                sf::IntRect _endRect;
            
                Animation(sf::Sprite& sprite, sf::Texture& textureSheet,
                    float animationTimer,
                    int startFrameX, int startFrameY, int framesX, int framesY,
                    int width, int height)
                    : _sprite(sprite), _textureSheet(textureSheet),
                    _animationTimer(animationTimer), _timer(0.f),
                    _done(false),
                    _width(width), _height(height) {

                        // compute frame position
                        this->_timer = 0.f;
                        this->_startRect = sf::IntRect(startFrameX * width, startFrameY * height, width, height);
                        this->_curRect =  this->_startRect;
                        this->_endRect = sf::IntRect(framesX * width, framesY * height, width, height);

                        this->_sprite.setTexture(this->_textureSheet, true);
                        this->_sprite.setTextureRect(this->_startRect);
                }

                // accessors/getters
                const bool& isDone() const {
                    return this->_done;
                }

                // functions

                // update
                const bool& play(const float &dt) {
                    /*
                    Function to play an animation
                    */
                    this->_done = false;
                    // update timer
                    this->_timer += 100.f * dt;

                    if (this->_timer >= this->_animationTimer) {
                        // reset timer
                        this->_timer = 0.f;

                        // animate while final animation frame not reached
                        if (this->_curRect != this->_endRect) {
                            this->_curRect.left += this->_width;
                        }

                        // reset
                        else {
                            this->_curRect.left = this->_startRect.left;
                            this->_done = true;
                        }

                        this->_sprite.setTextureRect(this->_curRect);
                    }
                    return this->_done;
                }

                const bool& play(const float &dt, float modPercentage) {
                    /*
                    Function to play an animation with a modifier percentage.
                    The modifier percentage acts as a safeguard to better play the animation when sped up or slowed down.
                    */
                    
                    // minimum value
                    if (modPercentage < 0.5f) {
                        modPercentage = 0.5f;
                    }

                    this->_done = false;

                    // update timer
                    this->_timer += modPercentage * 100.f * dt;

                    if (this->_timer >= this->_animationTimer) {
                        // reset timer
                        this->_timer = 0.f;

                        // animate while final animation frame not reached
                        if (this->_curRect != this->_endRect) {
                            this->_curRect.left += this->_width;
                        }

                        // reset
                        else {
                            this->_curRect.left = this->_startRect.left;
                            this->_done = true;
                        }

                        this->_sprite.setTextureRect(this->_curRect);
                    }
                    return this->_done;
                }

                void reset() {
                    this->_timer = this->_animationTimer; // instantly switch to new animation
                    this->_curRect = this->_startRect;
                }
        };

        sf::Sprite& _sprite;
        sf::Texture& _textureSheet;
        std::map<std::string, Animation*> _animations;
        Animation* _lastAnimation;
        Animation* _priorityAnimation;

    

    protected:
    public:
        AnimationComponent(sf::Sprite& sprite, sf::Texture& textureSheet);
        virtual ~AnimationComponent();

        // accessors/getters
        const bool& isDone(const std::string key);

        // functions
        void addAnimation(const std::string key,
            float animationTimer,
            int startFrameX, int startFrameY, int framesX, int framesY,
            int width, int height);

        // update
        const bool& play(const std::string key, const float& dt, const bool priority = false);
        const bool& play(const std::string key, const float& dt,
            const float& modifier, const float modifierMax,
            const bool priority = false);

};


#endif