#include "player.h"

Player::Player(sf::Vector2<float> init_position) {
	this->height = 10.f;
	this->width = 10.f;
	this->shape.push_back(sf::RectangleShape());
	this->shape[0].setSize(sf::Vector2f(this->width,this->height));
	this->shape[0].setOrigin(this->width/2,this->height/2);
	this->speed = 150.f;
	this->size = 1;
	this->position.push_back(init_position);
}

Player::~Player() {
}

void Player::update_position(float elapsed_time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->velocity.x =-this->speed;
		this->velocity.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->velocity.x =this->speed;
		this->velocity.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->velocity.y =-this->speed;
		this->velocity.x = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->velocity.y =this->speed;
		this->velocity.x = 0;
	}
	this->previous_position = this->position[0];
	for (int s = 0; s < this->size; s++) {
		this->position[s] += this->velocity * elapsed_time;
	}
	this->right_edge = this->position[0].x + this->width/2;
	this->left_edge = this->position[0].x - this->width/2;
	this->top_edge = this->position[0].y - this->height/2;
	this->bot_edge = this->position[0].y + this->height/2;
}

void Player::handle_collision(std::string collision_type) {
	if (collision_type == "right") {
		this->position[0]  = this->previous_position;
		this->velocity.x = 0;
	}
	if (collision_type == "left") {
		this->position[0] = this->previous_position;
		this->velocity.x = 0;
	}
	if (collision_type == "up") {
		this->position[0] = this->previous_position;
		this->velocity.y = 0;
	}
	if (collision_type == "down"){
		this->position[0] = this->previous_position;
		this->velocity.y = 0;
	}
	if (collision_type == "food") {
		//Increase player size.
		this->shape.push_back(sf::RectangleShape());
		this->position.push_back(this->position[this->size-1]+sf::Vector2f(this->right_edge, 0));
		this->shape[size].setSize(sf::Vector2f(this->width,this->height));
		this->shape[size].setOrigin(this->width/2,this->height/2);
		this->size += 1;
	}
	return;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Transform render_position;
	render_position.translate(this->position[0]);
	states.transform = render_position;
	target.draw(this->shape[0], states);
	for (int s = 1; s < this->size; s++) {
		render_position.translate(sf::Vector2f(this->width/2, 0));
		states.transform = render_position;
		target.draw(this->shape[s], states);
	}
}

