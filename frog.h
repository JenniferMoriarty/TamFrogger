#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class frog {
private:
	int lives;
	float xVel;
	float yVel;
	int health = 100;
	int timer = 0;
	int timeLeft = 100;

public:
	float xpos;
	float ypos;
	frog();
	void update();
	void draw(sf::RenderWindow& window);
	void jump(bool* keys);
	float returnX() { return xpos; }
	float returnY() { return ypos; }
	void ded();
	int returnLives() { return lives; }
	void printInfo() { cout << "My position is " << xpos << ", " << ypos << endl; }
	int getHealth() { return health; }
};

