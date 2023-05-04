#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"
#include "frog.h"
#include "car.h"
#include <time.h>
#include <vector>
using namespace std;

int main() {
	
	srand(time(NULL));
	int timer = 0;
	bool keys[] = { false, false, false, false };

	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger!");

	frog player;

	vector<car*> cars; // make a vector of pointers to car objects
	for (int i = 0; i < 5; i++) // handles number of cars in each row
		for (int j = 0; j < 1; j++) {// handles number of rows we have
			cars.push_back(new car(i * 400 + 100, j * 200 + 480, LEFT));
			cars.push_back(new car(i * 300 + 200, j * 200 + 600, RIGHT));
		}
	while (screen.isOpen()) { //gameloop
		//input section
		sf::Event event;
		while (screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else {
				keys[UP] = false;
				keys[DOWN] = false;
				keys[LEFT] = false;
				keys[RIGHT] = false;
			}
				
		}
		//physics section
		timer++;
		player.update();
		if (timer > 300) {
			player.jump(keys);
			timer = 0;
		}
		for (vector<car*>::iterator i = cars.begin(); i != cars.end(); i++)
		{
			(*i)->move();
		}
		//collision section
		for (vector<car*>::iterator i = cars.begin(); i != cars.end(); i++)
		{
			if ((*i)->collide(player.xpos, player.ypos) == true) {
				player.ded();
			}
		}


		//render section
		screen.clear();

		for (vector<car*>::iterator i = cars.begin(); i != cars.end(); i++)
		{
			(*i)->draw(screen);
		}

		player.draw(screen);

		screen.display();
	}
	cout << "GAME OVER" << endl;
	return 0;
}