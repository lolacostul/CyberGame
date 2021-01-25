// core
#include "stdafx.hpp"

#include "Defibrillator.hpp"

Defibrillator::Defibrillator() {
	this->set_name("Defibrillator");
	this->set_range(18);
	this->set_power(16);
}

std::string Defibrillator::toString() const {
	std::stringstream ss;
	ss << Weapon::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Defibrillator const & d) {
	out << d.toString();
	return out;
}