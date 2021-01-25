// core
#include "stdafx.hpp"

#include "State.hpp"

/*------ init -----*/
void State::initFonts() {
    if (!this->_font.loadFromFile("resources/fonts/Garuda.ttf")) {
        throw("ERROR::COULD NOT LOAD FONT");
    }
}

/*------ constructor/desctuctor -----*/
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states) {
	this->_window = window;
	this->_supportedKeys = supportedKeys;
	this->_states = states;
	this->_quit = false;
}

State::~State() {

}

/*------ functions -----*/
const bool & State::getQuit() const {
	return this->_quit;
}

void State::endState() {
	this->_quit = true;
}

/*------ update -----*/
void State::updateMousePosition() {
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->_window);
	this->mousePosView = this->_window->mapPixelToCoords(sf::Mouse::getPosition(*this->_window));

	// std::cout << this->mousePosView.x << ", " << this->mousePosView.y << "\n";
}

/*------ utils -----*/
std::string State::toString() const {
	std::stringstream ss;
	ss << "State: " << typeid(State).name() << std::endl;
	return ss.str(); 
}

std::ostream& operator<<(std::ostream & out, State const & s) {
	out << s.toString();
	return out;
}