#include "frog.h"
#include "globals.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>

frog::frog() {
	xpos = 500;
	ypos = 920;
	lives = 5;
	xVel = 0;
	yVel = 0;
}

void frog::draw(sf::RenderWindow& window) {
	sf::RectangleShape FrogPic(sf::Vector2f(20, 20));
	FrogPic.setFillColor(sf::Color(50, 200, 50));
	FrogPic.setPosition(xpos, ypos);
	window.draw(FrogPic);

	//health bar outline
	sf::RectangleShape rectangle2(sf::Vector2f(100, 20));
	rectangle2.setFillColor(sf::Color::Black);
	rectangle2.setOutlineThickness(3);
	rectangle2.setOutlineColor(sf::Color::Red);
	rectangle2.setPosition(800, 50);
	window.draw(rectangle2);

	//health bar
	sf::RectangleShape rectangle(sf::Vector2f(health, 20));
	rectangle.setFillColor(sf::Color::Yellow);
	rectangle.setPosition(800, 50);
	window.draw(rectangle);

	//timer bar outline
	sf::RectangleShape rectangle4(sf::Vector2f(100, 20));
	rectangle4.setFillColor(sf::Color::Black);
	rectangle4.setOutlineThickness(3);
	rectangle4.setOutlineColor(sf::Color::Red);
	rectangle4.setPosition(100, 50);
	window.draw(rectangle4);

	//timer bar
	sf::RectangleShape rectangle3(sf::Vector2f(timeLeft, 20));
	rectangle3.setFillColor(sf::Color::Yellow);
	rectangle3.setPosition(100, 50);
	window.draw(rectangle3);

	//add text here to label health and timer bars
}

void frog::update() {
	timer++;
	if (timer % 1000 == 0)
		timeLeft -= 1;
	if (timeLeft < 0) {
		timeLeft = 100;
		lives--;
		//play beep, reset position


	}
}

void frog::jump(bool* keys) {
	if (keys[UP] == true)
		yVel = -60;
	else if (keys[DOWN] == true)
		yVel = 60;
	else if (keys[LEFT] == true)
		xVel = -60;
	else if (keys[RIGHT] == true)
		xVel = 60;
	else {
		yVel = 0;
		xVel = 0;
	}

	
	xpos += xVel;
	ypos += yVel;
}

void frog::ded() {
	
	health -= 10;
	xpos = 500;
	ypos = 920;
	if (health < 0) {
		health = 100;
		lives--;
		Beep(500, 500);
	}
}