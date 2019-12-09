#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("PAC-FONT.ttf"))
	{
		//handle error; 
	}




	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Yellow);
	menu[0].setString("Start Game");
	menu[0].setPosition(sf::Vector2f(width / 1.5, height / (MAX_NUMBER_OF_ITEMS)* 3));

	
	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Blue);
	menu[1].setString("Hall Of Fame");
	menu[1].setPosition(sf::Vector2f(width / 1.7, height / (MAX_NUMBER_OF_ITEMS)* 4));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Blue);
	menu[2].setString("Creator's Information");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS)* 5));


	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Blue);
	menu[3].setString("Exit Game");
	menu[3].setPosition(sf::Vector2f(width / 1.5, height / (MAX_NUMBER_OF_ITEMS)* 6));

	
	

	selecteditemindex = 0;
}


Menu::~Menu()
{
}
void Menu::draw(sf::RenderWindow &window){
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}

}
void Menu::Moveup(){
	if (selecteditemindex -1 >=0)
	{
		menu[selecteditemindex].setColor(sf::Color::Blue);
		selecteditemindex--;
		menu[selecteditemindex].setColor(sf::Color::Yellow);
	}

}

void Menu::Movedown(){
	if (selecteditemindex + 1 <MAX_NUMBER_OF_ITEMS)
	{
		menu[selecteditemindex].setColor(sf::Color::Blue);
		selecteditemindex++;
		menu[selecteditemindex].setColor(sf::Color::Yellow);
	}

}