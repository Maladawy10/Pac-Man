#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <iostream>
#include "Menu.h"
using namespace sf;
using namespace std;
Font fon, fon1;
string username;
int size = -1;
int main()
{
backtothewindow:
	string free;
	RenderWindow window(VideoMode(800, 800), "Pac-Man");
	RectangleShape mouse(Vector2f(5, 5));
	Menu menu(window.getSize().x / 2, window.getSize().y / 2);
	sf::Texture texture;
	if (!texture.loadFromFile("Mpac.png"))
	{
		// handle error;
	}
	sf::Sprite sprite(texture);
	sprite.setPosition(sf::Vector2f(135, 0));
	sprite.setScale(sf::Vector2f(3, 4));

	sf::SoundBuffer buffer;
	int x = 0;
	if (!buffer.loadFromFile("pacman_beginning.wav"))
	{
		//handle error;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.setLoop(x == 0);
	sound.setVolume(20);
	sound.play();

	sf::Texture Texture1;
	if (!Texture1.loadFromFile("pacman10.png"))
	{
		// handle error;
	}
	sf::Sprite Sprite1(Texture1);
	Sprite1.setPosition(sf::Vector2f(90, 190));
	Sprite1.setScale(sf::Vector2f(0.5, 0.6));

	/*1*/		sf::Texture pacy1;
	if (!pacy1.loadFromFile("pacy1.png"))
	{
		// handle error;
	}
	sf::Sprite pacy(pacy1);
	pacy.setPosition(sf::Vector2f(235, 310));
	pacy.setScale(sf::Vector2f(0.09, 0.1));



	/*2*/	sf::Texture pacy2;
	if (!pacy2.loadFromFile("pacy2.png"))
	{
		// handle error;
	}
	sf::Sprite pacyy(pacy2);
	pacyy.setPosition(sf::Vector2f(200, 410));
	pacyy.setScale(sf::Vector2f(0.09, 0.1));


	/*3*/		sf::Texture pacy3;
	if (!pacy3.loadFromFile("pacy3.png"))
	{
		// handle error;
	}
	sf::Sprite pacyyy(pacy3);
	pacyyy.setPosition(sf::Vector2f(100, 510));
	pacyyy.setScale(sf::Vector2f(0.09, 0.1));


	/*4*/ sf::Texture pacy4;
	if (!pacy4.loadFromFile("pacy4.png"))
	{
		// handle error;
	}
	sf::Sprite pacyyyy(pacy4);
	pacyyyy.setPosition(sf::Vector2f(230, 610));
	pacyyyy.setScale(sf::Vector2f(0.09, 0.1));

	Text cp;
	if (!fon1.loadFromFile("type.otf"))
	{
		//handle error;
	}
	cp.setFont(fon1);
	cp.setColor(Color::White);
	cp.setString("CopyRights@2019");
	cp.setPosition(Vector2f(250, 750));

	Text user1;
	user1.setFont(fon1);
	user1.setColor(Color::Blue);
	user1.setPosition(Vector2f(250, 310));


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.Moveup();
					break;
				case sf::Keyboard::Down:
					menu.Movedown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressed())
					{
					case 0:
						while (window.isOpen())
						{
							while (true)
							{
								mouse.setPosition(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
								window.clear();
								Text start;
								if (!fon.loadFromFile("PAC-FONT.TTF"))
								{
									//handle error;
								}
								start.setFont(fon);
								start.setColor(Color::Yellow);
								start.setString("Username:");
								start.setPosition(Vector2f(0, 310));

								while (window.pollEvent(event))
								{
									if (event.type == Event::TextEntered)
									{

										if (!Keyboard::isKeyPressed(Keyboard::Backspace))
										{
											size++;
											username += event.text.unicode;
											user1.setString(username);


										}
										else
										{
											if (size > 0)
											{
												size = -1;
											username = username.substr(0, --size);
											
										    }
									    else{
												
												username = free;

										    }
											user1.setString(username);
										}
									}

								}

								Text start1;
								if (!fon.loadFromFile("PAC-FONT.TTF"))
								{
									//handle error;
								}
								start1.setFont(fon);
								start1.setColor(Color::Blue);
								start1.setString("Ready?!");
								start1.setPosition(Vector2f(280, 410));
								Text cp;
								if (!start1.getGlobalBounds().intersects(mouse.getGlobalBounds()))
								{
									start1.setColor(Color::Blue);
								}
								if (start1.getGlobalBounds().intersects(mouse.getGlobalBounds()))
								{
									start1.setColor(Color::Yellow);
									switch (event.key.code)
									{
									case Mouse::Left:
										while (window.isOpen())
										{
											while (true)
											{
												window.clear();
												window.draw(sprite);
												window.display();
												while (window.pollEvent(event))
												{
													switch (event.type){

													case sf::Event::Closed:
														goto backtothewindow;
														break;

													}

												} 
											}
										}
										break;
									}

								}
								if (!fon1.loadFromFile("type.otf"))
								{
									//handle error;
								}
								cp.setFont(fon1);
								cp.setColor(Color::White);
								cp.setString("CopyRights@2019");
								cp.setPosition(Vector2f(250, 750));

								window.draw(cp);
								window.draw(sprite);
								window.draw(start);
								window.draw(user1);
								window.draw(start1);
								window.display();

								while (window.pollEvent(event))
								{
									switch (event.type){

									case sf::Event::Closed:
										goto backtothewindow;
										break;

									}

								}

							}

						}

						break;

					case 1:
						while (window.isOpen())
						{


							while (true)
							{


								window.clear();
								Text cp;
								if (!fon1.loadFromFile("type.otf"))
								{
									//handle error;
								}
								cp.setFont(fon1);
								cp.setColor(Color::White);
								cp.setString("CopyRights@2019");
								cp.setPosition(Vector2f(250, 750));
								window.draw(cp);
								window.draw(sprite);
								window.display();

								while (window.pollEvent(event))
								{
									switch (event.type){

									case sf::Event::Closed:
										goto backtothewindow;
										break;

									}

								}

							}

						}

						break;
					case 2:
						while (window.isOpen())
						{

							while (true)
							{


								window.clear();

								if (!fon1.loadFromFile("type.otf"))
								{
									//handle error;
								}
								Text cr;
								cr.setFont(fon1);
								cr.setColor(Color::Yellow);
								cr.setString("Name:Magdy Adel [Section:13]");
								cr.setPosition(Vector2f(0, 200));
								Text cr1;
								cr1.setFont(fon1);
								cr1.setColor(Color::Red);
								cr1.setString("Name:Michael Raafat [Section:13]");
								cr1.setPosition(Vector2f(0, 250));
								Text cr2;
								cr2.setFont(fon1);
								cr2.setColor(Color::Blue);
								cr2.setString("Name:Mohammed Kandil [Section:15]");
								cr2.setPosition(Vector2f(0, 300));
								Text cr3;
								cr3.setFont(fon1);
								cr3.setColor(Color::Cyan);
								cr3.setString("Name:Monem Mohammed [Section:18]");
								cr3.setPosition(Vector2f(0, 350));
								Text cr4;
								cr4.setFont(fon1);
								cr4.setColor(Color::Magenta);
								cr4.setString("Name:Mostafa Hossam [Section:17]");
								cr4.setPosition(Vector2f(0, 400));
								Text cr5;
								cr5.setFont(fon1);
								cr5.setColor(Color::Green);
								cr5.setString("Name:Mahmoud Khaled [Section:15]");
								cr5.setPosition(Vector2f(0, 450));
								Text cp;
								cp.setFont(fon1);
								cp.setColor(Color::White);
								cp.setString("CopyRights@2019");
								cp.setPosition(Vector2f(250, 750));
								window.draw(sprite);
								window.draw(cr);
								window.draw(cr1);
								window.draw(cr2);
								window.draw(cr3);
								window.draw(cr4);
								window.draw(cr5);
								window.draw(cp);
								window.display();

								while (window.pollEvent(event))
								{
									switch (event.type){

									case sf::Event::Closed:
										goto backtothewindow;
										break;

									}

								}

							}

						}
						break;
					case 3:
						window.close();
						sound.stop();
						break;
					}

					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				sound.stop();
				break;

			case sf::Keyboard::Escape:
				window.close();
				sound.stop();

				break;

			}
		}
		window.clear();
		window.draw(sprite);
		window.draw(Sprite1);
		menu.draw(window);
		window.draw(pacy);
		window.draw(pacyy);
		window.draw(pacyyy);
		window.draw(pacyyyy);
		window.draw(cp);
		window.display();
	}
	system("pause");
	return 0;
}