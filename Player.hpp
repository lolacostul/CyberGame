#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "Character.hpp"
#include "Weapon.hpp"

class Player : public Character {
	private:
		// variables
		bool _attacking;

		// init
		void initVariables();
		
	protected:
		int _xp = 0;
		Weapon *_weapon;
	public:
		// Player();
		Player(float x, float y, sf::Texture& textureSheet);
		virtual ~Player() {};

		// setter
		void setXP(int givenXP) {this->_xp += givenXP;}

		// getter
		int getXP() const {return this->_xp;}

		// functions

		// update
		void updateAttack();
		void updateAnimation(const float& dt);
		virtual void update(const float& dt);

		// utils
		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Player const & p);
};

#endif