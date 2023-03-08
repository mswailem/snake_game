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

std::string Game::detect_collisions() {
	if (this->player->right_edge >= this->vm.width)	return "right";
	if (this->player->bot_edge >= this->vm.height) return "down";
	if (this->player->left_edge <= 0)	return "left";
	if (this->player->top_edge <= 0) return "up";
	float dx = this->player->position[0].x - this->food->position.x;
	float dy = this->player->position[0].y - this->food->position.y;
	if (std::abs(dx) <= (this->player->width/2+this->food->width/2) && std::abs(dy) <= (this->player->height/2+this->food->height/2)) {
		this->food->reposition();
		return "food";
	}
	return "NONE";
}

void Game::update() {
	this->pollEvents();
	this->frametime = this->clock.getElapsedTime();
	this->player->get_input();
	if (frametime.asSeconds() >	time_to_upadate.asSeconds()) {
		this->player->update_position();
		this->player->handle_collision(this->detect_collisions());
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
