// core
#include "stdafx.hpp"

#include "Game.hpp"

/*----- init -----*/
void Game::initVariables() {
    this->_window = NULL;
    this->_fullscreen = false;
    this->_dt = 0.f;
}

void Game::initWindow() {
    std::ifstream ifs("config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string gameTitle = "Game";
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned framerateLimit = 120;
    bool verticalSync = false;
    unsigned antialiasingLevel = 0;

    if (ifs.is_open()) {
        std::getline(ifs, gameTitle);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> fullscreen;
        ifs >> framerateLimit;
        ifs >> verticalSync;
        ifs >> antialiasingLevel;
    }

    ifs.close();

    this->_fullscreen = fullscreen;
    this->_windowSettings.antialiasingLevel = antialiasingLevel;
    if (this->_fullscreen) {
        this->_window = new sf::RenderWindow(windowBounds, gameTitle, sf::Style::Fullscreen, _windowSettings);
    }
    else {
        this->_window = new sf::RenderWindow(
            windowBounds, gameTitle, sf::Style::Titlebar | sf::Style::Close, _windowSettings
        );
    }
    
    this->_window->setFramerateLimit(framerateLimit);
    this->_window->setVerticalSyncEnabled(verticalSync);
}

void Game::initKeys() {

    std::ifstream ifs("config/keyboard_layout.ini");

    if (ifs.is_open()) {
        std::string key = "";
        int key_value = 0;

        while (ifs >> key >> key_value) {
            this->_supportedKeys[key] = key_value;
        }   
    }

    ifs.close();
}

void Game::initStates() {
    this->_states.push(new MainMenuState(this->_window, &this->_supportedKeys, &this->_states));
}


/*----- constructor/destructor -----*/
Game::Game() {
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game() {
    delete this->_window;

    while(!this->_states.empty()) {
        delete this->_states.top();
        this->_states.pop();
    }
}

/*----- core -----*/

void Game::endApplication() {
    std::cout << "Ending application." << "\n";
}


/*----- update -----*/

void Game::updateSFMLEvents()
{
    while (this->_window->pollEvent(this->_event)) {
        if (this->_event.type == sf::Event::Closed) {
            this->_window->close();
        }
    }
}

void Game::updateDt() {
    /* Updates the deltatime (dt) variable with the time it takes to update and render a frame. */
    this->_dt = this->dtClock.restart().asSeconds();

    // std::cout << this->_dt << "\n";
}


void Game::update() {
    this->updateSFMLEvents();

    if (!this->_states.empty()) {
        this->_states.top()->update(this->_dt);

        if (this->_states.top()->getQuit()) {
            this->_states.top()->endState();
            delete this->_states.top();
            this->_states.pop();
        }   
    }

    // app quit
    else {
        this->endApplication();
        this->_window->close();
    }
}

/*----- render -----*/

void Game::render() {

    this->_window->clear();

    // render items
    if (!this->_states.empty()) {
        this->_states.top()->render();
    }

    this->_window->display();
}

/*----- run -----*/

void Game::run() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("resources/audio/eighti.wav")) {
        throw("ERROR::COULD NOT LOAD FONT");
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.play();

	while (this->_window->isOpen()) {
        this->updateDt();
        // this->titleScreen();
        this->update();
        this->render();
    }
}
