/*!
 * \file snake.cpp
 * \ author Edson
 * \date December, 2020
 */
#include <iostream>
#include "lib/snake.h"

int main(int argc, char *argv[]){

	SnakeGame game;

	game.initialize_game(argc, argv);

	while(not game.game_over()){

		game.process();
		game.update();
		game.render();
	}

	return 0;
}
