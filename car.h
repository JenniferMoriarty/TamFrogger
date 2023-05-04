#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"
using namespace std;

class car {
private:
	float xpos;
	float ypos;
	int green = rand() % 100 + 200;
	int blue = rand() % 100 + 200;
	int directionG;
public:
	car(int x, int y, int direction);
	void draw(sf::RenderWindow& window);
	void move();
	bool collide(int x, int y);
	void printInfo() { cout << "I am a car and my position is" << xpos << ", " << ypos << endl; }
};

