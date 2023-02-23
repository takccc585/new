#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"

struct EnemyObj {
	sf::Texture texture;
	sf::Sprite sprite;
	float offset;
};

void roadObjInit(EnemyObj& obj, sf::Vector2f pos, std::string fileName, float offset) {
	obj.texture.loadFromFile(fileName);
	obj.sprite.setTexture(obj.texture);
	obj.sprite.setPosition(pos);
	obj.offset = offset;
}

void EnemyObjUpdate(EnemyObj& obj) {
	srand(time(NULL));
	float x = rand() % 5;
	obj.sprite.move(0, ROADOBJ_SPEED);
	if (obj.sprite.getPosition().y >= WINDOW_HEIGHT) {
		if (x == 1) {
			obj.sprite.setPosition(100.f, -100.f);
		}
		if (x == 2) {
			obj.sprite.setPosition(200.f, -100.f);
		}
		if (x == 3) {
			obj.sprite.setPosition(300.f, -100.f);
		}
		if (x == 4) {
			obj.sprite.setPosition(400.f, -100.f);
		}
	}
}

void EnemyObjDraw(sf::RenderWindow& window) {
}