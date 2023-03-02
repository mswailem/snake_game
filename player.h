#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

class Player : public sf::Drawable {
	private:
		std::vector<sf::RectangleShape> shape;
		sf::Vector2<float> previous_position;
	public:
		float width;
		float height;
		std::vector<sf::Vector2<float>> position;
		sf::Vector2<float> velocity;
		float right_edge;
		float left_edge;
		float top_edge;
		float bot_edge;
		float speed;
		int size;

	Player();
	Player(sf::Vector2<float> init_position); 
	
	virtual ~Player();

	void update_position(float elapsed_time); 
	void handle_collision(std::string collision_type);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
};

#endif // !PLAYER_H
