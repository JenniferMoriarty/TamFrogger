#include <SFML/Graphics.hpp>
#include "car.h"

car::car(int x, int y, int direction) {
	xpos = x;
	ypos = y;
	directionG = direction;
}

void car::draw(sf::RenderWindow& window) {
	sf::RectangleShape vehicle(sf::Vector2f(100, 50));
	vehicle.setFillColor(sf::Color(250, green, blue));
	vehicle.setPosition(xpos, ypos);
	window.draw(vehicle);
}

void car::move() {
	if (directionG == LEFT) {
		if (xpos < -100)
			xpos = 1100;
		xpos -= .1;
	}
	else if (directionG == RIGHT) {
		if (xpos > 1100)
			xpos = -100;
		xpos += .1;
	}
}
bool car::collide(int x, int y) {
	if (xpos + 100 > x && xpos <= x && ypos + 50 > y && ypos <= y) {
		cout << "U DED" << endl;
		return true;
	}
	else
		return false;
}
