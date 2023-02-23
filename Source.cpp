#include <SFML/Graphics.hpp>
#include"settings.h"
#include"roadobj.h"
#include"car.h"
#include"enemies.h"
#include"textobj.h"
#include"textGameOver.h"
#include"explosion.h"


using namespace sf;

enum GameStatus{Play, GameOver};

int main()
{
	GameStatus game = Play;

	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		"cho",
		Style::Close | Style::Titlebar
	);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadObj grass;
	roadObjInit(grass, GRASS_START_POS, GRASS_FILE_NAME, 0.f);
	RoadObj road;
	roadObjInit(road, ROAD_START_POS, ROAD_FILE_NAME, 100.f);
	RoadObj grass1;
	roadObjInit(grass1, GRASS_START_POS_1, GRASS_FILE_NAME_1, 0.f);
	RoadObj road1;
	roadObjInit(road1, ROAD_START_POS_1, ROAD_FILE_NAME_1, 100.f);
	CarObj car;
	carObjInit(car, CAR_START_POS, CAR_FILE_NAME);
	EnemyObj enemy;
	roadObjInit(enemy, ENEMY_START_POS, ENEMY_FILE_NAME, 100.f);
	TextObj scoreText;
	textInit(scoreText, score);
	Explosion  exp;
	expInit(exp, carGetPosition(car));
	TextOverObj obj;
	textOverInit(obj, "GAME OVER", Vector2f(WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2));


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		switch (game) {
		case Play:
			roadObjUpdate(road);
			roadObjUpdate(grass);
			roadObjUpdate(road1);
			roadObjUpdate(grass1);
			carObjUpdate(car);
			EnemyObjUpdate(enemy);
			textUpdate(scoreText, score);
			if (car.sprite.getGlobalBounds().intersects(enemy.sprite.getGlobalBounds())) {
				for (int q1=1; q1 <= 1; q1++) {
					expUpdate(exp);
					expDraw(window, exp);
					if (exp.frame>=6) {
						game = GameOver;
					}
				}
			}
			window.clear();
			window.draw(grass.sprite);
			window.draw(road.sprite);
			window.draw(grass1.sprite);
			window.draw(road1.sprite);
			window.draw(car.sprite);
			window.draw(enemy.sprite);
			textDraw(window, scoreText);
			window.display();
			break;
		case GameOver:
			window.clear();
			textOverDraw(window, obj);
			window.display();
		}
	}
	return 0;
}