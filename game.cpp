#include "game.h"
#include <SFML/System/Time.hpp>
#include <cmath>

Game::Game() {
	this->init_vars();
	this->init_window();
	this->player = new Player(sf::Vector2f((float)this->vm.width/2, (float)this->vm.height/2));
	this->food = new Food();
	this->time_to_upadate = sf::seconds(0.2f);
}

Game::~Game() {
	delete this->window;
}

void Game::init_vars() {
	this->window = nullptr;
}

void Game::init_window() {
	this->vm.width=300;
	this->vm.height=300;

	this->window = new sf::RenderWindow(this->vm, "Snake Game");
}

void Game::pollEvents() {

	while (this->window->pollEvent(this->event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();
		break;

	}
}


void Game::update() {
	this->pollEvents();
	this->frametime = this->clock.getElapsedTime();
	this->input_handler.handle_inputs(this->player);
	if (frametime.asSeconds() >	time_to_upadate.asSeconds()) {
		this->collision_handler.detect_collisions(this->player,this->food,this->vm);
		this->player->update_position();
		this->clock.restart();
	}
}

void Game::render() {

        this->window->clear();
		this->window->draw(*player);
		this->window->draw(*food);
        window->display();
}

const bool Game::running() const {
	return this->window->isOpen();
}
