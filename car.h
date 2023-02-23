#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"
#include"roadobj.h"

struct CarObj {
	sf::Texture texture;
	sf::Sprite sprite;
};
void carObjInit(CarObj& obj, sf::Vector2f pos, std::string fileName) {
	obj.texture.loadFromFile(fileName);
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
}
void carObjUpdate(CarObj& obj) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		obj.sprite.move(CAR_SPEED, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		obj.sprite.move(-CAR_SPEED, 0);
	}
	if (obj.sprite.getPosition().x <= 0) {
		obj.sprite.setPosition(0.f, WINDOW_HEIGHT - 250.f);
	}
	if (obj.sprite.getPosition().x + 100.f >= WINDOW_WIDTH) {
		obj.sprite.setPosition(WINDOW_WIDTH - 100.f, WINDOW_HEIGHT - 250.f);
	}
	if ((obj.sprite.getPosition().x <= 90) or (obj.sprite.getPosition().x + 90.f >= 500) or (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
		ROADOBJ_SPEED = 3.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		ROADOBJ_SPEED = 10.f;
	}
	else {
		ROADOBJ_SPEED = 6.f;
	}
}
void carObjDraw(sf::RenderWindow& window) {
}

sf::Vector2f carGetPosition(const CarObj& car) {
	return sf::Vector2f{ car.sprite.getGlobalBounds().left, car.sprite.getGlobalBounds().top };
}