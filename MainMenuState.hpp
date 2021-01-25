#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.hpp"
#include "Button.hpp"

class MainMenuState: public State {
	private:
    bool _selectedClass;
    bool _selectedRace;

    // variables
    std::map<std::string, Button*> buttons;

    // texts
    sf::Text _titleText;
    sf::Text _classChoice;
    sf::Text _raceChoice;
    sf::Text _infoText;

    // sprites
    sf::Sprite _titleScreenSprite;
    sf::Sprite _gunbreakerSprite;
    sf::Sprite _fixerSprite;
    sf::Sprite _volterSprite;
    sf::Sprite _hackerSprite;
    sf::Sprite _humanSprite;
    sf::Sprite _cyborgSprite;
    sf::Sprite _androidSprite;
    sf::Sprite _undeadCyborgSprite;

    // textures
    sf::Texture _titleScreenTexture;
    sf::Texture _gunbreakerTexture;
    sf::Texture _fixerTexture;
    sf::Texture _volterTexture;
    sf::Texture _hackerTexture;
    sf::Texture _humanTexture;
    sf::Texture _cyborgTexture;
    sf::Texture _androidTexture;
    sf::Texture _undeadCyborgTexture;

	// functions
	void initKeybinds();
    void initButtons();

	public:
		MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>* states);

		virtual ~MainMenuState();

		// functions
		void show();
		void selectClass();
		void selectRace();

		// update
		void updateInput(const float& dt);
		void updateButtons();
		void update(const float& dt);

		// render
		void renderButtons(sf::RenderTarget& target);
		void render(sf::RenderTarget* target = NULL);
};

#endif