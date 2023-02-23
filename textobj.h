#pragma once
#include "SFML/Graphics.hpp"
#include "settings.h"

struct TextObj {
	sf::Font font;
	sf::Text text;
};

void textInit(TextObj& textobj, int score) {
	textobj.font.loadFromFile("arial.ttf");
	textobj.text.setString(std::to_string(score));
	textobj.text.setFont(textobj.font);
	textobj.text.setCharacterSize(TEXT_SIZE);
	textobj.text.setPosition(TEXT_START_POS);
}

void textUpdate(TextObj& textobj, int score) {
	textobj.text.setString(std::to_string(score));
}

void textDraw(sf::RenderWindow& window, const TextObj& textobj) {
	window.draw(textobj.text);
}