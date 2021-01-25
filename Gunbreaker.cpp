// core
#include "stdafx.hpp"

#include "Gunbreaker.hpp"


Gunbreaker::Gunbreaker(float x, float y, sf::Texture& texture) : Player (x, y, texture) {
	std::cout << "Gunbreaker's default constructor\n";
	this->set_characterClass("Gunbreaker");
	this->set_hp(80);
	this->set_mana(20);
	this->_weapon = new TankGun();
}

Gunbreaker::~Gunbreaker() {
	delete _weapon;
}


std::string Gunbreaker::toString() const {
	std::stringstream ss;
	ss << "Class: " << this->_characterClass << this->_weapon->toString() << Player::toString();
	return ss.str();
}

std::ostream& operator<<(std::ostream & out, Gunbreaker const & gb) {
	out << gb.toString();
	return out;
}