#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
#pragma once

class Weapon {
	protected:
		std::string _name = "-";
		int _range = 0;	// melee, range
		int _power = 0;
	public:
		Weapon();
		Weapon(std::string);
		~Weapon();

		// Setter
		void set_name(std::string givenName) {this->_name = givenName;}
		void set_range(int givenRange) {this->_range = givenRange;}
		void set_power(int givenPower) {this->_power = givenPower;}

		// Getter
		std::string get_name() const {return this->_name;}
		int get_range() const {return this->_range;}
		int get_power() const {return this->_power;}

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, Weapon const & w);
};

#endif