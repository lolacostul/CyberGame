// core
#include "stdafx.hpp"

#include "GameState.hpp"

/*----- init -----*/
std::random_device rd;
std::mt19937 mt(rd());


void GameState::initKeybinds() {
    std::ifstream ifs("config/keybinds/gamestate.ini");

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

void GameState::initTextures() {
    // players
    if (!this->_textures["HUMAN_SHEET"].loadFromFile("resources/images/sprites/player/HUMAN_SHEET.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_HUMAN_TEXTURE");
    }
    if (!this->_textures["UNDEADCYBORG_SHEET"].loadFromFile("resources/images/sprites/player/UNDEADCYBORG_SHEET.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_UNDEADCYBORG_TEXTURE");
    }
    if (!this->_textures["ANDROID_SHEET"].loadFromFile("resources/images/sprites/player/ANDROID_SHEET.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_ANDROID_TEXTURE");
    }
    if (!this->_textures["CYBORG_SHEET"].loadFromFile("resources/images/sprites/player/CYBORG_SHEET.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_CYBORG_TEXTURE");
    }

    // enemies
    if (!this->_textures["COVID_TEXT"].loadFromFile("resources/images/sprites/enemy/covid.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_COVID_TEXTURE");
    }
    if (!this->_textures["REMOTE_TEXT"].loadFromFile("resources/images/sprites/enemy/remote_work.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_REMOTE_TEXTURE");
    }
    if (!this->_textures["VACCINE_TEXT"].loadFromFile("resources/images/sprites/enemy/vaccine.png")) {
        throw("ERROR::GAMESTATE::COULD_NOT_LOAD_VACCINE_TEXTURE");
    }
}

void GameState::initPlayers() {
    this->_player = new Player(20, 475, this->_textures["HUMAN_SHEET"]);

    this->_scoreText.setFont(this->_font);
    this->_scoreText.setString(std::to_string(this->_player->getXP()));
    this->_scoreText.setCharacterSize(40);
    this->_scoreText.setFillColor(sf::Color::White);
    this->_scoreText.setStyle(sf::Text::Bold);
    this->_scoreText.setPosition(sf::Vector2f(0.f, 0.f));
}

void GameState::initEnemies() {
    unsigned int windowMaxX = this->_window->getSize().x;
    unsigned int windowMaxY = this->_window->getSize().y - 58;
    std::uniform_real_distribution<float> dist(0.f, windowMaxY);

    std::vector<float> enemyPositionsY;

    for (unsigned int i=1; i < this->_textures.size() + 1; ++i) {
        enemyPositionsY.push_back(dist(mt));
    }
    
    // init enemies for the special level
    this->_enemies.push_back(new Enemy(windowMaxX, enemyPositionsY[0], this->_textures["COVID_TEXT"], false));
    this->_enemies.push_back(new Enemy(windowMaxX, enemyPositionsY[1], this->_textures["REMOTE_TEXT"], false));
    this->_enemies.push_back(new Enemy(windowMaxX, enemyPositionsY[2], this->_textures["VACCINE_TEXT"], false));
}

/*----- constructor/desctuctor -----*/

GameState::GameState(
        sf::RenderWindow* window,
        std::map<std::string, int>* supportedKeys,
        std::stack<State*>* states
    ) : State(window, supportedKeys, states) {
    this->initFonts();
    this->initKeybinds();
    this->initTextures();
    this->initPlayers();
    this->initEnemies();
}

GameState::~GameState() {
    delete this->_player;
    this->_enemies.clear();
}

/*----- update -----*/
void GameState::updateScore() {
    this->_scoreText.setString(std::to_string(this->_player->getXP()));
}

void GameState::updateInput(const float& dt) {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_LEFT")))) {
		this->_player->move(-1.f, 0.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_RIGHT")))) {
		this->_player->move(1.f, 0.f, dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_UP")))) {
		this->_player->move(0.f, -1.f, dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("MOVE_DOWN")))) {
		this->_player->move(0.f, 1.f, dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->_keybinds.at("CLOSE")))) {
		this->endState();
	}
}

void GameState::updateCombat(Enemy* enemy, const float& dt) {
	//Check for enemy damage
	if (this->_player->getGlobalBounds().intersects(enemy->getGlobalBounds())) {
        // find which enemy was touched
        std::vector<Enemy*>::iterator it;
        it = std::find (this->_enemies.begin(), this->_enemies.end(), enemy);
        int enemyTouched = this->_enemy->getIndex(this->_enemies, enemy);

        // remove enemy if touched by player
        this->_enemies.erase(this->_enemies.begin() + enemyTouched);
        this->_player->setXP(1);
        this->updateScore();
	}
}

void GameState::update(const float& dt) {
    this->updateMousePosition();
	this->updateInput(dt);

    this->_player->update(dt);

    for (auto enemy : this->_enemies) {
        enemy->move(-1.f, 0.f, dt);
	    enemy->update(dt);
        if (enemy->getPosition().x < -372) {
            this->_enemies.clear();
            this->initEnemies();
        }
        this->updateCombat(enemy, dt);
    }
    if (this->_enemies.size() <= 0) {
        this->initEnemies();
    }
}

void GameState::render(sf::RenderTarget* target) {
    // sf::Sprite title_screen_sprite;
    // sf::Texture title_screen_texture;
    // if (!title_screen_texture.loadFromFile("resources/images/cyberpunk-street.png")) {
    //     std::cout << "Title screen texture error\n";
    // }
    // title_screen_sprite.setTexture(title_screen_texture);
    // title_screen_sprite.setScale(0.5, 0.5);   // adjust size of sprite
    // this->_window->draw(title_screen_sprite);

    if (!target) {
        target = this->_window;
    }
    
    this->_player->render(*target);
    for (auto Enemy : this->_enemies) {
	    Enemy->render(*target);
    }
    
    target->draw(this->_scoreText);
}
