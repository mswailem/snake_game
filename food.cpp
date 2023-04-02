#include "food.h"

Food::Food() {
	srand(time(0));
	float x_pos = (float) rand()/(float)RAND_MAX * 300;
	float y_pos = (float) rand()/(float)RAND_MAX * 300;
	this->width = 10.f;
	this->height = 10.f;
	this->position = sf::Vector2f(x_pos,y_pos);
	this->shape.setSize(sf::Vector2f(this->width,this->height));
	this->shape.setOrigin(this->width/2,this->height/2);
	this->shape.setFillColor(sf::Color(255, 0 ,0,255));
	this->right_edge = this->position.x + this->width/2;
	this->left_edge = this->position.x - this->width/2;
	this->top_edge = this->position.y - this->height/2;
	this->bot_edge = this->position.y + this->height/2;
}

Food::~Food() {
}

void Food::reposition() {
	float x_pos = (float) rand()/(float)RAND_MAX * 300;
	float y_pos = (float) rand()/(float)RAND_MAX * 300;
	this->position = sf::Vector2f(x_pos,y_pos);
	//TODO: Check if the new position is not inside the player
}

void Food::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	sf::Transform render_position;
	render_position.translate(this->position);
	states.transform = render_position;
	target.draw(this->shape, states);
}
