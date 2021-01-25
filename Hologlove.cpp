// core
#include "stdafx.hpp"

#include "Hologlove.hpp"

Hologlove::Hologlove() {
	this->set_name("Hologlove");
	this->set_range(18);
	this->set_power(16);
}

std::string Hologlove::toString() const {
	std::stringstream ss;
	ss << Weapon::toString();
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, Hologlove const & d) {
	out << d.toString();
	return out;
}