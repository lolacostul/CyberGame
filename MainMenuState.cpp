// core
#include "stdafx.hpp"

#include "MainMenuState.hpp"

/*----- init -----*/
void MainMenuState::initKeybinds() {
    std::ifstream ifs("config/keybinds/mainmenustate.ini");

    if (ifs.is_open()) {
        std::string key = "";
        std::string key_name = "";

        // get key int value from _supportedKeys
        while (ifs >> key >> key_name) {
            this->_keybinds[key] = this->_supportedKeys->at(key_name);
        }       
    }

    ifs.close();
}

void MainMenuState::initButtons() {
    int buttonWidth = 150;
    int buttonHeight = 50;
    int centeredWidth = this->_window->getSize().x / 2 - (buttonWidth / 2);

    // core
    this->buttons["START_GAME"] = new Button(
        centeredWidth, 400, buttonWidth, buttonHeight,
        &this->_font, "New game",
        30,
        sf::Color(0, 0, 0, 200),
        sf::Color(255, 255, 255, 255),
        sf::Color(170, 170, 170, 200),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );

    this->buttons["EXIT"] = new Button(
        centeredWidth, 500, buttonWidth, buttonHeight,
        &this->_font, "Quit",
        30,
        sf::Color(0, 0, 0, 200),
        sf::Color(255, 255, 255, 255),
        sf::Color(170, 170, 170, 200),
        sf::Color(70, 70, 70, 0),
        sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0)
    );

    int classButtonWidth = 100;
    int classButtonHeight = 80;
    int raceButtonWidth = 100;
    int raceButtonHeight = 80;
    int classButtonY = 121;
    int raceButtonY = 221;
    int firstClassButtonX = 170;
    int firstRaceButtonX = 170;

    // classes
    this->buttons["GUNBREAKER_CLASS"] = new Button(
        firstClassButtonX, classButtonY, classButtonWidth, classButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    this->buttons["FIXER_CLASS"] = new Button(
        firstClassButtonX + classButtonWidth + 30, classButtonY, classButtonWidth, classButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    this->buttons["VOLTER_CLASS"] = new Button(
        firstClassButtonX + (classButtonWidth + 30) * 2, classButtonY, classButtonWidth, classButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    this->buttons["HACKER_CLASS"] = new Button(
        firstClassButtonX + (classButtonWidth + 30) * 3, classButtonY, classButtonWidth, classButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    // races
    this->buttons["HUMAN_RACE"] = new Button(
        firstRaceButtonX, raceButtonY, raceButtonWidth, raceButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    this->buttons["CYBORG_RACE"] = new Button(
        firstRaceButtonX + raceButtonWidth + 30, raceButtonY, raceButtonWidth, raceButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    this->buttons["ANDROID_RACE"] = new Button(
        firstRaceButtonX + (raceButtonWidth + 30) * 2, raceButtonY, raceButtonWidth, raceButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );

    this->buttons["UNDEADCYBORG_RACE"] = new Button(
        firstRaceButtonX + (raceButtonWidth + 30) * 3, raceButtonY, raceButtonWidth, raceButtonHeight,
        &this->_font, "",
        0,
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0),
        sf::Color(255, 255, 255, 0)
    );
}


/*----- constructor/desctuctor -----*/
MainMenuState::MainMenuState(
        sf::RenderWindow* window,
        std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states
    ) : State(window, supportedKeys, states) {

    // init
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    // show main menu
    this->show();

}

MainMenuState::~MainMenuState() {
    auto it = this->buttons.begin();
    for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
        delete it->second;
    }
}

/*----- functions -----*/
void MainMenuState::show() {

    // Fond
    if (!this->_titleScreenTexture.loadFromFile("resources/images/title_screen_texture.jpg")) {
        std::cout << "Title screen texture error\n";
    }
    this->_titleScreenSprite.setTexture(this->_titleScreenTexture);

    // Font & Text of Title 

    this->_titleText.setFont(this->_font); // add font to _titleText
    this->_titleText.setString("Cyberpunk RPG Game");
    this->_titleText.setCharacterSize(40);  // set _titleText size
    this->_titleText.setFillColor(sf::Color::Black);  // set _titleText's color
    this->_titleText.setStyle(sf::Text::Bold);   // set _titleText's style
    this->_titleText.setPosition(sf::Vector2f(200.f, 0.f));   // set _titleText's position

    // Class text

    this->_classChoice.setFont(this->_font); // add font to _classChoice
    this->_classChoice.setString("Select a class:");
    this->_classChoice.setCharacterSize(20);  // set _classChoice size
    this->_classChoice.setFillColor(sf::Color::Black);  // set _classChoice's color
    this->_classChoice.setStyle(sf::Text::Underlined);   // set _classChoice's style
    this->_classChoice.setPosition(sf::Vector2f(20.f, 120.f));   // set _classChoice's position

    // Class choice (sprites)
    this->_gunbreakerTexture.loadFromFile("resources/images/gunbreaker.png");
    if (!this->_gunbreakerTexture.loadFromFile("resources/images/gunbreaker.png")) {
        std::cout << "Gunbreaker Texture error\n";
    }
    // this->_gunbreakerTexture.setSmooth(true);    // lissage de la _gunbreakerTexture
    this->_gunbreakerSprite.setTexture(_gunbreakerTexture); // add _gunbreakerTexture to _gunbreakerSprite
    this->_gunbreakerSprite.setScale(0.6, 0.6);  // set text size
    this->_gunbreakerSprite.setPosition(sf::Vector2f(170.f, 120.f)); // set _gunbreakerSprite's absolute position

    this->_fixerTexture.loadFromFile("resources/images/fixer.png");
    if (!this->_fixerTexture.loadFromFile("resources/images/fixer.png")) {
        std::cout << "Fixer Texture error\n";
    }
    // this->_fixerTexture.setSmooth(true);    // lissage de la _fixerTexture
    this->_fixerSprite.setTexture(_fixerTexture); // add _fixerTexture to _fixerSprite
    this->_fixerSprite.setScale(0.6, 0.6);  // set text size
    this->_fixerSprite.setPosition(sf::Vector2f(300.f, 120.f)); // set _fixerSprite's absolute position

    this->_volterTexture.loadFromFile("resources/images/volter.png");
    if (!this->_volterTexture.loadFromFile("resources/images/volter.png")) {
        std::cout << "Volter Texture error\n";
    }
    // this->_volterTexture.setSmooth(true);    // lissage de la _volterTexture
    this->_volterSprite.setTexture(_volterTexture); // add _volterTexture to _volterSprite
    this->_volterSprite.setScale(0.6, 0.6);  // set text size
    this->_volterSprite.setPosition(sf::Vector2f(430.f, 120.f)); // set _volterSprite's absolute position

    this->_hackerTexture.loadFromFile("resources/images/hacker.png");
    if (!this->_hackerTexture.loadFromFile("resources/images/hacker.png")) {
        std::cout << "Hacker Texture error\n";
    }
    // this->_hackerTexture.setSmooth(true);    // lissage de la _hackerTexture
    this->_hackerSprite.setTexture(_hackerTexture); // add _hackerTexture to _hackerSprite
    this->_hackerSprite.setScale(0.6, 0.6);  // set text size
    this->_hackerSprite.setPosition(sf::Vector2f(560.f, 120.f)); // set _hackerSprite's absolute position

    // Race text

    this->_raceChoice.setFont(this->_font); // add font to _raceChoice
    this->_raceChoice.setString("Select a race:");
    this->_raceChoice.setCharacterSize(20);  // set _raceChoice size
    this->_raceChoice.setFillColor(sf::Color::Black);  // set _raceChoice's color
    this->_raceChoice.setStyle(sf::Text::Underlined);   // set _raceChoice's style
    this->_raceChoice.setPosition(sf::Vector2f(20.f, 220.f));   // set _raceChoice's position

    this->_humanTexture.loadFromFile("resources/images/human.png");
    if (!this->_humanTexture.loadFromFile("resources/images/human.png")) {
        std::cout << "Human Texture error\n";
    }
    // this->_humanTexture.setSmooth(true);    // lissage de la _humanTexture
    this->_humanSprite.setTexture(_humanTexture); // add _humanTexture to _humanSprite
    this->_humanSprite.setScale(0.65, 0.65);  // set text size
    this->_humanSprite.setPosition(sf::Vector2f(170.f, 220.f)); // set _humanSprite's absolute position

    this->_cyborgTexture.loadFromFile("resources/images/cyborg.png");
    if (!this->_cyborgTexture.loadFromFile("resources/images/cyborg.png")) {
        std::cout << "Cyborg Texture error\n";
    }
    // this->_cyborgTexture.setSmooth(true);    // lissage de la _cyborgTexture
    this->_cyborgSprite.setTexture(_cyborgTexture); // add _cyborgTexture to _cyborgSprite
    this->_cyborgSprite.setScale(0.75, 0.75);  // set text size
    this->_cyborgSprite.setPosition(sf::Vector2f(300.f, 220.f)); // set _cyborgSprite's absolute position

    this->_androidTexture.loadFromFile("resources/images/android.png");
    if (!this->_androidTexture.loadFromFile("resources/images/android.png")) {
        std::cout << "Android Texture error\n";
    }
    // this->_androidTexture.setSmooth(true);    // lissage de la _androidTexture
    this->_androidSprite.setTexture(this->_androidTexture); // add _androidTexture to _androidSprite
    this->_androidSprite.setScale(0.78, 0.78);  // set text size
    this->_androidSprite.setPosition(sf::Vector2f(430.f, 220.f)); // set _androidSprite's absolute position

    this->_undeadCyborgTexture.loadFromFile("resources/images/undead_cyborg.png");
    if (!this->_undeadCyborgTexture.loadFromFile("resources/images/undead_cyborg.png")) {
        std::cout << "Undead Cyborg Texture error\n";
    }
    // this->_undeadCyborgTexture.setSmooth(true);    // lissage de la _undeadCyborgTexture
    this->_undeadCyborgSprite.setTexture(_undeadCyborgTexture); // add _undeadCyborgTexture to _undeadCyborgSprite
    this->_undeadCyborgSprite.setScale(0.75, 0.75);  // set text size
    this->_undeadCyborgSprite.setPosition(sf::Vector2f(560.f, 220.f)); // set _undeadCyborgSprite's absolute position


    // Info Texts
    this->_infoText.setFont(this->_font); // add font to _infoText
    this->_infoText.setCharacterSize(20);  // set _infoText size
    this->_infoText.setFillColor(sf::Color::Black);  // set _infoText's color
    this->_infoText.setStyle(sf::Text::Underlined);   // set _infoText's style
    this->_infoText.setPosition(sf::Vector2f(350.f, 400.f));   // set _infoText's position
}


/*----- update -----*/

void MainMenuState::updateInput(const float& dt) {
}

void MainMenuState::updateButtons() {
    // update all the buttons
    for (auto &it : this->buttons) {
        it.second->update(this->mousePosView);
    }   
}

void MainMenuState::update(const float& dt) {
    this->updateMousePosition();
	this->updateInput(dt);

	this->updateButtons();

    this->selectClass();
    this->selectRace();

    if (this->buttons["START_GAME"]->isPressed()) {
        this->_states->push(new GameState(this->_window, this->_supportedKeys, this->_states));
    }

    if (this->buttons["EXIT"]->isPressed()) {
        this->endState();
    }

    if (this->_selectedClass == true && this->_selectedRace == true) {
        std::cout << this->_player << "\n";
        this->_states->push(new GameState(this->_window, this->_supportedKeys, this->_states));
        this->_selectedClass = false;
        this->_selectedRace = false;
    }
    
}

/*----- render -----*/

void MainMenuState::renderButtons(sf::RenderTarget& target) {
    for (auto &it : this->buttons) {
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target) {

    if (!target) {
        target = this->_window;
    }    

    target->draw(this->_titleScreenSprite);

    // Class shape
    target->draw(this->_humanSprite);
    target->draw(this->_cyborgSprite);
    target->draw(this->_androidSprite);
    target->draw(this->_undeadCyborgSprite);
    target->draw(this->_gunbreakerSprite);
    target->draw(this->_hackerSprite);
    target->draw(this->_volterSprite);
    target->draw(this->_fixerSprite);

    // Texts
    target->draw(this->_raceChoice);
    target->draw(this->_classChoice);
    target->draw(this->_titleText);
    target->draw(this->_infoText);

    this->renderButtons(*target);

    // TO REMOVE
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 30);
    mouseText.setFont(this->_font);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);

}


void MainMenuState::selectClass() {
	// Gunbreaker gb;
    if (this->buttons["GUNBREAKER_CLASS"]->isPressed()) {
    	std::cout << "Gunbreaker selected\n";
	    Gunbreaker* gb = new Gunbreaker(0.f, 0.f, this->_textures["PLAYER_IDLE"]);
    	std::cout << gb << std::endl;
        this->_player = *gb;
        this->_selectedClass = true;
    }

    else if (this->buttons["FIXER_CLASS"]->isPressed()) {
    	std::cout << "Fixer selected\n";
	    Fixer* fx = new Fixer(0.f, 0.f, this->_textures["PLAYER_IDLE"]);
    	std::cout << fx << std::endl;
        this->_player = *fx;
        this->_selectedClass = true;
    }

    else if (this->buttons["VOLTER_CLASS"]->isPressed()) {
    	std::cout << "Volter selected\n";
	    Volter* vt = new Volter(0.f, 0.f, this->_textures["PLAYER_IDLE"]);
    	std::cout << vt << std::endl;
        this->_player = *vt;
        this->_selectedClass = true;
    }

    else if (this->buttons["HACKER_CLASS"]->isPressed()) {
    	std::cout << "Hacker selected\n";
	    Hacker* hk = new Hacker(0.f, 0.f, this->_textures["PLAYER_IDLE"]);
    	std::cout << hk << std::endl;
        this->_player = *hk;
        this->_selectedClass = true;
    }

    // default
    // return gb;
}


void MainMenuState::selectRace() {
    if (this->buttons["HUMAN_RACE"]->isPressed()) {
    	std::cout << "Human selected\n";
        this->_player.set_race("Human");
        this->_selectedRace = true;
    }

    else if (this->buttons["CYBORG_RACE"]->isPressed()) {
    	std::cout << "Cyborg selected\n";
        this->_player.set_race("Cyborg");
        this->_selectedRace = true;
    }

    else if (this->buttons["ANDROID_RACE"]->isPressed()) {
    	std::cout << "Android selected\n";
        this->_player.set_race("Android");
        this->_selectedRace = true;
    }

    else if (this->buttons["UNDEADCYBORG_RACE"]->isPressed()) {
    	std::cout << "UndeadCyborg selected\n";
        this->_player.set_race("UndeadCyborg");
        this->_selectedRace = true;
    }
}
