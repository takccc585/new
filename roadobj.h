#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"

struct RoadObj {
	sf::Texture texture;
	sf::Sprite sprite;
	float offset;
};

void roadObjInit(RoadObj& obj, sf::Vector2f pos, std::string fileName, float offset) {
	obj.texture.loadFromFile(fileName);
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
	obj.offset = offset;
}

void roadObjUpdate(RoadObj& obj) {
	obj.sprite.move(0, ROADOBJ_SPEED);
	if (obj.sprite.getPosition().y >= WINDOW_HEIGHT) {
		obj.sprite.setPosition(obj.offset, -WINDOW_HEIGHT);
		score += 0.5;
	}
}

void roadObjDraw(sf::RenderWindow& window) {
}