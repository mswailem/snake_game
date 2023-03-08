#include "player.h"

Player::Player(sf::Vector2<float> init_position) {
	this->height = 10.f;
	this->width = 10.f;
	this->shape.push_back(sf::RectangleShape());
	this->shape[0].setSize(sf::Vector2f(this->width,this->height));
	this->shape[0].setOrigin(this->width/2,this->height/2);
	this->speed = 1.f;
	this->size = 1;
	this->position.push_back(init_position);
}

Player::~Player() {
}

void Player::update_position() {
	this->previous_position = this->position[0];
	if(this->velocity.x + this->velocity.y != 0) {
		for (int s = this->size - 1; s > 0; s--) {
			this->position[s] = this->position[s-1];
		}
	}
	this->position[0] += this->width * this->velocity;
	this->right_edge = this->position[0].x + this->width/2;
	this->left_edge = this->position[0].x - this->width/2;
	this->top_edge = this->position[0].y - this->height/2;
	this->bot_edge = this->position[0].y + this->height/2;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Transform render_position;
	render_position.translate(this->position[0]);
	//std::cout << this->position[0].x << " " << this->position[0].y << std::endl;
	//std::cout << this->position[1].x << " " << this->position[1].y << std::endl;
	states.transform = render_position;
	target.draw(this->shape[0], states);
	for (int s = 1; s < this->size; s++) {
		render_position.translate(this->position[s] - this->position[s-1]);
		states.transform = render_position;
		target.draw(this->shape[s], states);
	}
}

