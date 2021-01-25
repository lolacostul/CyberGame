#ifndef __ENEMY_HPP__
#define __ENEMY_HPP__

#include "Character.hpp"
#include "Weapon.hpp"

class Enemy : public Character {
	private:
		// variables
		bool _attacking;
		bool _needsFlipping;

		// init
		void initVariables();
		
	protected:
		Weapon *_weapon;
	public:
		Enemy(float x, float y, sf::Texture& textureSheet, bool needsFlipping);
		virtual ~Enemy() {};

		// update
		void updateAttack();
		void updateAnimation(const float& dt);
		virtual void update(const float& dt);

		// utils
		int getIndex(std::vector<Enemy*> v, Enemy* e);
		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Enemy const & m);
		friend bool operator==(const Enemy& e1, const Enemy& e2);
};

#endif