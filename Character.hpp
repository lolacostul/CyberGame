#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"
#include "AnimationComponent.hpp"

class Character {
	private:
		// init
		void initVariables();

	protected:
		std::string _characterClass;
		std::string _race;
		int _id;
		int _hp;
		int _mana;
		bool _isDead;
		std::vector<std::string> _raceVect{"Human", "Cyborg", "Android", "UndeadCyborg"};

		// graphical
		sf::Sprite _sprite;

		// movement
		HitboxComponent* _hitboxComponent;
		MovementComponent* _movementComponent;
		AnimationComponent* _animationComponent;

	public:
		Character();
		~Character();

		// setters
		void set_characterClass(std::string givenName) {this->_characterClass = givenName;}
		void set_race(std::string givenRace) {this->_race = givenRace;}
		void set_hp(int givenHP) {this->_hp = givenHP;}
		void set_mana(int givenMana) {this->_mana = givenMana;}
		void set_isDead(bool givenIsDead) {this->_isDead = givenIsDead;}

		// accessors/getters
		std::string get_characterClass() const {return this->_characterClass;}
		std::string get_race() const {return this->_race;}
		int get_hp() const {return this->_hp;}
		int get_mana() const {return this->_mana;}
		bool get_isDead() const {return this->_isDead;}
		const sf::Vector2f& getPosition() const;
		const sf::FloatRect getGlobalBounds() const;

		// functions
		virtual void sufferDamages(int nbDamages);
		virtual void attack(Character &cible, int damages);
		void heal(int nbHeal);
		void isAlive();
		void flipSprite();

		// components
		void setTexture(sf::Texture& texture);
		void setPosition(float x, float y);
		void createHitboxComponent(sf::Sprite& sprite,
			float offsetX, float offsetY,
			float width, float height,
			sf::Color outlineColor);
		void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
		void createAnimationComponent(sf::Texture& textureSheet);

		// update
		virtual void update(const float& dt);

		// rendering
		virtual void render(sf::RenderTarget& target);

		// actions
		virtual void move(const float x, const float y, const float& dt);

		// utils
		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Character const & c);
};

#endif