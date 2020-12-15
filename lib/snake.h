/*!
 * \file snake.h
 * \ author Edson
 * \date December, 2020
 */

#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <vector>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>	
#include <cmath>

/// This class Represents the basic Snake
/*!
 * This Class represents the snake with life and size making changes.
 *
 */
class Snake{

	private:
		int m_life; //!< Count life of snake.
		int m_size; //!< Count the current size of snake.

	public:
		Snake(); //!< Constructor

		int get_life(){ return m_life; } //!< return the current life.
		int get_size(){ return m_size; } //!< return the current size of snake.

		void loss_life(); //!< reduces the current life.
		void set_size(int value); //!< Change the size of snake.
};

/// This Class representes the level and its settings.
/*!
 * This class is used to store the amount of lines and columns of current
 * maze, also store the spawn coordinates and store the maze and characters.
 */
class Level{

	private:
		int m_line; //!< Save the amount of lines.
		int m_colmn; //!< Save the amount of columns.
		int m_spawn_x; //!< Save the coordinate x of spawn.
		int m_spawn_y; //!< Save the coordinate y of spawn.
		std::deque<std::string> m_maze; //!< deque with all characters of current maze.

	public:
		Level() //!< Constructor
		: m_line{1}, m_colmn{1}
		{ /* empty */ }

		int get_line(){ return m_line; } //!< Return the current lines of maze.
		int get_colmn(){ return m_colmn; } //!< Return the current columns of maze.
		int get_spawn_x(){ return m_spawn_x; } //!< Return the x coord. of spawn.
		int get_spawn_y(){ return m_spawn_y; } //!< Return the y coord. of spawn.
		void set_line(int value); //!< Change the value of lines.
		void set_colmn(int value); //!< Change the value of columns.
		void set_spawn_x(int value); //!< Change the value of x spawn.
		void set_spawn_y(int value); //!< Change the value of y spawn.
		void add_line(std::string value); //!< add a new line in the current Maze.

		void delete_maze(); //!< This function delete the maze, to update to a new phase.
		void print_maze(); //!< This function print the current maze.
		bool check_spawn(); //!< Return a boolean if spawn exist.
};

/*!
 * This class represent a AI of Player
 *
 * This class use Backtracking To resolve the Maze and save in a steps in a deque,
 * To recover the solution, we need do push_front in deque and changes coord. of player
 */
class Player{

	private:
		int m_position_x; //!< Current position x of player.
		int m_position_y; //!< Current position y of player.
		int m_position_x_2; //!< Current position x of player.
		int m_position_y_2; //!< Current position y of player.
		int m_position_x_3; //!< Current position x of player.
		int m_position_y_3; //!< Current position y of player.
		int m_position_x_4; //!< Current position x of player.
		int m_position_y_4; //!< Current position y of player.
		int m_position_x_5; //!< Current position x of player.
		int m_position_y_5; //!< Current position y of player.
		int m_point;


		int m_line; //!< the amount of lines of maze.
		int m_colmn; //!< the amount of columns of maze.
		int m_point_x; //!< The current point position x.
		int m_point_y; //!< The current point position y.
		Snake m_snake;

		/// Struct with Coord. of solution of maze.
		struct Direction{
			int x;
			int y;

		}cdir;

		std::deque<Direction> m_solution; //!< Deque that stores list of solucion.

	public:

		std::deque<std::string> m_maze; //!< The current maze.

		int get_position_x(){ return m_position_x; } //!< Return position x of player.
		int get_position_y(){ return m_position_y; } //!< Return position y of player.
		int get_position_x_2(){ return m_position_x_2; } //!< Return position x of player.
		int get_position_y_2(){ return m_position_y_2; } //!< Return position y of player.
		int get_position_x_3(){ return m_position_x_3; } //!< Return position x of player.
		int get_position_y_3(){ return m_position_y_3; } //!< Return position y of player.
		int get_position_x_4(){ return m_position_x_3; } //!< Return position x of player.
		int get_position_y_4(){ return m_position_y_3; } //!< Return position y of player.
		int get_position_x_5(){ return m_position_x_3; } //!< Return position x of player.
		int get_position_y_5(){ return m_position_y_3; } //!< Return position y of player.
		int get_line(){ return m_line; } //!< Return the amount of lines of maze.
		int get_colmn(){ return m_colmn; } //!< Return the amount of colmns of maze.
		int get_point_x(){ return m_point_x; } //!< Return the current x position of point(Apple).
		int get_point_y(){ return m_point_y; } //!< Return the current y position of point(Apple).
		int solution_size(){ return m_solution.size(); } //!< Return how many steps of solution.
		int get_points(){ return m_point; } //!< Return current points in a current maze.

		void set_position_x(int value); //!< Change position x of player.
		void set_position_y(int value); //!< Change position y of player.
		void set_position_x_2(int value); //!< Change position x of player.
		void set_position_y_2(int value); //!< Change position y of player.
		void set_position_x_3(int value); //!< Change position x of player.
		void set_position_y_3(int value); //!< Change position y of player.
		void set_position_x_4(int value); //!< Change position x of player.
		void set_position_y_4(int value); //!< Change position y of player.
		void set_position_x_5(int value); //!< Change position x of player.
		void set_position_y_5(int value); //!< Change position y of player.
		void set_line(int value); //!< Change the number of lines of maze.
		void set_colmn(int value); //!< Change the number columns of maze.
		void set_point_x(int value); //!< Change the position x of point(Apple).
		void set_point_y(int value); //!< Change the position y of point(Apple).
		void set_points(int value); //!< Change the amount points in current maze.

		void add_line(std::string value);//!< Add a new line to maze.
		Direction next_move(); //!< Recover the move of solution.
		bool find_solution(std::deque<std::string> maze, int x, int y); //!< Backtracking that solve the maze.
		void print_maze(); //!< print the current maze.
		void delete_maze(); //!< delete the current maze.
		void generate_food(); //!< generate the point(Apple) in valid position.
		void delete_food(int x, int y); //!< delete point(Apple), when the player take it,
		void solve(int x, int y); //!< call the Backtracking to solve the maze.
		void delete_solve(); //!< delete list of solution.
};

class SnakeGame{

	private:
		int m_process; //!< Store the process to show the screen and change the process
		int m_status; //!< Store if the game continue or stop
		int m_points; //!< Store the points of maze, if new maze is start, this value restart
		int m_score; //!< Store the total score in session
		Level m_level; //!< the Object of the Level and all its properties
		Player m_player; //!< the Object of the Player and all its properties
		Snake m_snake; //!< The Object of the Snake and all its properties
		std::string m_file_name; //!< Store the file name
		std::ifstream m_file; //!< the file with maze
		std::string m_line; //!< store the line
		std::string m_temp; //!< aux string

	public:

		enum GameProcess{
			UNINFORMED_FILE = 1,	//!< 1 Name not found
			REPORTED_FILE,			//!< 2 Name found
			FILE_DIDNT_OPEN,		//!< 3 File has not been opened
			FILE_OPEN,				//!< 4 File was opened
			END_OF_FILE,			//!< 5 End of file
			CURRENT_LEVEL,			//!< 6 Current level
			NEXT_LEVEL,				//!< 7 Next Level is ready
			NO_FOUND_SPAWN,			//!< 8 Did not find the spawn
			WELCOME_MSG,			//!< 9 Welcome message
			START_GAME,				//!< 10 Start Game
			GO_TO_NEXT_LEVEL		//!< 11 Go to the next level.
		};

		enum GameStatus{
			EXIT_GAME = 1,			//!< Exit of game
			CONTINUE_GAME			//!< Game execution continues
		};

		int get_process(){ return m_process; } //!< return the current process of game
		int get_status(){ return m_status; } //!< return the current status exit or continue in the game
		int get_points(){ return m_points; } //!< return the current point of current maze
		int get_score(){ return m_score; } //!< return the current point of game
		std::string get_file_name(){ return m_file_name; } //!< Return the current name file

		void set_process(int value); //!< Change process to show the corret message
		void set_status(int value); //!< change status to exit game or continue
		void set_file_name(std::string value); //!< Change name file
		void set_points(int value); //!< change points of current maze
		void set_score(int value); //!< Change score
		void add_point(); //!< add 1 point up to 5 points in a maze
		void add_score(); //!< add 75 points in score.

		void initialize_game(int argc, char *argv[]); //!< First process of game
		void open_file(std::ifstream &file); //!< Open file with mazes
		void read_file(std::ifstream &file); //!< Read the file with mazes
		void process(); //!< Change the process of game
		void update(); //!< Update the status and process
		void render(); //!< Used to render all screens and maze
		bool game_over(); //!< Return true if game end
};

#endif
