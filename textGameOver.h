#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct TextOverObj {
	sf::Font font;
	sf::Text text;
};

void textOverInit(TextOverObj& textobj, std::string str, sf::Vector2f pos) {
	textobj.font.loadFromFile("arial.ttf");
	textobj.text.setString(str);
	textobj.text.setFont(textobj.font);
	textobj.text.setCharacterSize(TEXT_SIZE);
	textobj.text.setPosition(120.f, 400.f);
}

void textOverUpdate(TextOverObj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}

void textOverDraw(sf::RenderWindow& window, const TextOverObj& textobj) {
	window.draw(textobj.text);
}