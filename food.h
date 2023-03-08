#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef FOOD_H
#define FOOD_H

class Food : public sf::Drawable {

	private:

	public:
		sf::Vector2<float> position;
		sf::RectangleShape shape;
		float width;
		float height;
		float right_edge;
		float left_edge;
		float top_edge;
		float bot_edge;

	Food();

	void reposition();

	virtual ~Food();
	
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const; 
};

#endif
