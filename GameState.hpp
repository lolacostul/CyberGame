#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.hpp"


class GameState: public State {
	private:
		Player* _player;
    	sf::Text _scoreText;

		Enemy* _enemy;
		std::vector<Enemy*> _enemies;

		// init
		void initKeybinds();
		void initTextures();
		void initPlayers();
		void initEnemies();

	public:
		GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);
		virtual ~GameState();

		// functions

		// update
		void updateInput(const float& dt);
		void updateScore();
		void updateCombat(Enemy* enemy, const float &dt);
		void update(const float& dt);

		// render
		void render(sf::RenderTarget* target = NULL);
};

#endif