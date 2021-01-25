#ifndef __DEFIBRILLATOR_HPP__
#define __DEFIBRILLATOR_HPP__
#pragma once

#include "Weapon.hpp"

class Defibrillator : public Weapon {
	protected:
		
	public:
		Defibrillator();
		~Defibrillator() {};

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Defibrillator const & d);
};

#endif