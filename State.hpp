#ifndef STATE_H
#define STATE_H

// core
#include "stdafx.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Weapon.hpp"
#include "Gunbreaker.hpp"
#include "Fixer.hpp"
#include "Volter.hpp"
#include "Hacker.hpp"

class State {
	protected:

		// core variables
		std::stack<State*>* _states;
		sf::RenderWindow* _window;
		std::map<std::string, int>* _supportedKeys;
		std::map<std::string, int> _keybinds;
		bool _quit;
		Character _player;
		Character _monster;

		sf::Vector2i mousePosScreen;
		sf::Vector2i mousePosWindow;
		sf::Vector2f mousePosView;

		// resources
		sf::Font _font;
		std::map<std::string, sf::Texture> _textures;

		// functions

		// init keybinds for each state (a same key can do different thing depending on the state)
		virtual void initKeybinds() = 0;
		virtual void initFonts();

	public:
		State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~State();

		// functions
		const bool& getQuit() const;
		void endState();

		// update
		virtual void updateMousePosition();
		virtual void updateInput(const float& dt) = 0;
		virtual void update(const float& dt) = 0;

		// render
		virtual void render(sf::RenderTarget* target = NULL) = 0;

		// utils
		std::string toString() const;
		friend std::ostream& operator<<(std::ostream & out, State const & s);
};

#endif