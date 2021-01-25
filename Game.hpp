#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "MainMenuState.hpp"

class Game {
	private:
		sf::RenderWindow *_window;
		sf::Event _event;
		std::vector<sf::VideoMode> videoModes;
		sf::ContextSettings _windowSettings;
    	bool _fullscreen;

		std::stack<State*> _states;

		std::map<std::string, int> _supportedKeys;

		sf::Clock dtClock;
		float _dt;

	public:
		// constructor/destructor
		Game();
		virtual ~Game();

		// init
		void initVariables();
		void initWindow();
		void initKeys();
		void initStates();

		// core
		void endApplication();

		// update
		void updateDt();
		void updateSFMLEvents();
		void update();

		// render
		void render();

		// run
		void run();

};

#endif