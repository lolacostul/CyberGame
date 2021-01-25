#ifndef __HOLOGLOVE_HPP__
#define __HOLOGLOVE_HPP__

#include "Weapon.hpp"

class Hologlove : public Weapon {
	protected:
		
	public:
		Hologlove();
		~Hologlove() {};

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Hologlove const & d);
};

#endif