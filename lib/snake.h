#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <fstream>

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
		std::string m_maze[3] = {"#", ".", "*"};

	public:
		Level()
		: m_line{1}, m_colmn{1}
		{ /* empty */ }

		int get_line(){ return m_line; }
		int get_colmn(){ return m_colmn; }
		void set_line(int value);
		void set_column(int value);
};

class Player{

	bool find_solution();
	//Direction
};

class SnakeGame{

	private:
		int m_process;
		int m_status;
		Level m_level;
		std::string m_file_name;

	public:

		enum GameProcess{
			UNINFORMED_FILE = 1,
			REPORTED_FILE,
			FILE_DIDNT_OPEN
		};

		enum GameStatus{
			EXIT_GAME = 1,
			CONTINUE_GAME
		};

		int get_process(){ return m_error; }
		int get_status(){ return m_status; }
		std::string get_file_name(){ return m_file_name; }
		void set_process(int value);
		void set_status(int value);
		void set_file_name(std::string value);

		void initialize_game(int argc, char *argv[]);
		void process();
		void update();
		void render();
		bool game_over();
};

#endif
