#pragma once
#include "SFML\Graphics.hpp"
#define MAX_NUMBER_OF_ITEMS 4
class Menu
{
public:
	Menu(float width, float height );
	~Menu();
	void draw(sf::RenderWindow &window);
	void Moveup();
	void Movedown();
	int GetPressed()
	{
		return selecteditemindex;
	}
private:
	int selecteditemindex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

