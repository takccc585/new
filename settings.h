#pragma once
#include"settings.h"
#include <iostream>
#include <ctime>

const float WINDOW_WIDTH = 600;
const float WINDOW_HEIGHT = 1000;
int FPS = 60;

const sf::Vector2f GRASS_START_POS{ 0.f, 0.f };
const sf::Vector2f GRASS_START_POS_1{ 0.f, -1000.f };
const std::string GRASS_FILE_NAME{ "grass.jpg" };
const std::string GRASS_FILE_NAME_1{ "grass.jpg" };
const sf::Vector2f ROAD_START_POS{ 100.f, 0.f };
const sf::Vector2f ROAD_START_POS_1{ 100.f, -1000.f };
const std::string ROAD_FILE_NAME{ "road.png" };
const std::string ROAD_FILE_NAME_1{ "road.png" };
const sf::Vector2f CAR_START_POS{ 300.f, WINDOW_HEIGHT - 250.f };
const std::string CAR_FILE_NAME{ "car.png" };
const sf::Vector2f ENEMY_START_POS{ 300.f, WINDOW_HEIGHT + 250.f };
const std::string ENEMY_FILE_NAME{ "bochka.png" };
const float TEXT_SIZE = 60;
const sf::Vector2f TEXT_START_POS{ 450.f, 50.f };

float ROADOBJ_SPEED = 5.f;
const float CAR_SPEED = 7.f;
float score = 0;

const std::string name = "v";