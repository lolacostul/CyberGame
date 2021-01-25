// core
#include "stdafx.hpp"

#include "Hacker.hpp"


Hacker::Hacker(float x, float y, sf::Texture& texture) : Player (x, y, texture) {
	std::cout << "Hacker's default constructor\n";
	this->set_characterClass("Hacker");
	this->set_hp(65);
	this->set_mana(60);
	this->_weapon = new Drone();
}

Hacker::~Hacker() {
	delete _weapon;
}


std::string Hacker::toString() const {
	std::stringstream ss;
	ss << "Class: " << this->_characterClass << this->_weapon->toString() << Player::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Hacker const & hk) {
	out << hk.toString();
	return out;
}