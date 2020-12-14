#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <fstream>
#include <deque>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <cmath>

class Snake{

	private:
		int m_life;
		int m_size;
		std::string m_body[2] = {"x","o"};

	public:
		Snake();

		int get_life(){ return m_life; }
		std::string get_body(int a){return m_body[a]; }

		void loss_life();
};


class Level{

	private:
		int m_line;
		int m_colmn;
		int m_spawn_x;
		int m_spawn_y;
//		Player m_player;
		std::deque<std::string> m_maze;

	public:
		Level()
		: m_line{1}, m_colmn{1}
		{ /* empty */ }

		int get_line(){ return m_line; }
		int get_colmn(){ return m_colmn; }
		int get_spawn_x(){ return m_spawn_x; }
		int get_spawn_y(){ return m_spawn_y; }
		void set_line(int value);
		void set_colmn(int value);
		void set_spawn_x(int value);
		void set_spawn_y(int value);
		void add_line(std::string value);
		void delete_maze();
		void print_maze();
		bool check_spawn();
};

class Player{

	private:
		int m_position_x;
		int m_position_y;
		int m_line;
		int m_colmn;
		int m_point_x;
		int m_point_y;

		std::deque<std::string> m_maze;

		struct Direction{
			int x;
			int y;

		}cdir;


		std::deque<Direction> m_solution;

	public:

		int get_position_x(){ return m_position_x; }
		int get_position_y(){ return m_position_y; }
		int get_line(){ return m_line; }
		int get_colmn(){ return m_colmn; }
		int get_point_x(){ return m_point_x; }
		int get_point_y(){ return m_point_y; }
		int solution_size(){ return m_solution.size(); }

		void set_position_x(int value);
		void set_position_y(int value);
		void set_line(int value);
		void set_colmn(int value);
		void set_point_x(int value);
		void set_point_y(int value);

		void add_line(std::string value);
		Direction next_move();
		bool find_solution(std::deque<std::string> maze, int x, int y);
		void print_maze();
		void delete_maze();
		void generate_food();
		void delete_food(int x, int y);
		void solve(int x, int y);
		void delete_solve();
};

class SnakeGame{

	private:
		int m_process;
		int m_status;
		int m_points;
		Level m_level;
		Player m_player;
		Snake m_snake;
		std::string m_file_name;
		std::ifstream m_file;
		std::string m_line;
		std::string m_temp;

	public:

		enum GameProcess{
			UNINFORMED_FILE = 1,	// 1
			REPORTED_FILE,			// 2
			FILE_DIDNT_OPEN,		// 3
			FILE_OPEN,				// 4
			END_OF_FILE,			// 5
			CURRENT_LEVEL,			// 6
			NEXT_LEVEL,				// 7
			NO_FOUND_SPAWN			// 8
		};

		enum GameStatus{
			EXIT_GAME = 1,
			CONTINUE_GAME
		};

		int get_process(){ return m_process; }
		int get_status(){ return m_status; }
		int get_points(){ return m_points; }
		std::string get_file_name(){ return m_file_name; }

		void set_process(int value);
		void set_status(int value);
		void set_file_name(std::string value);
		void set_points(int value);
		void add_point();

		void initialize_game(int argc, char *argv[]);
		void open_file(std::ifstream &file);
		void read_file(std::ifstream &file);
		void process();
		void update();
		void render();
		bool game_over();
};

#endif
