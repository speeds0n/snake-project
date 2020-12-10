#include "../lib/snake.h"

/// Class Snake ///
Snake::Snake(){
	m_life = 5;
	m_size = 1;
}

void Snake::loss_life(){
	m_life--;
}

/// Class Level ///
void Level::set_line(int value){
	m_line = value;
}

void Level::set_column(int value){
	m_colmn = value;
}
/// Class SnakeGame ///

void SnakeGame::set_process(int value){
	m_process = value;
}

void SnakeGame::set_status(int value){
	m_status = value;
}

void SnakeGame::set_file_name( std::string value){
	m_file_name = value;
}

void SnakeGame::initialize_game(int argc, char *argv[]){

	if(argc == 1){ // Apenas o ./a.out foi digitado
		set_process(1);
	}else if(argc == 2){ // executavel + 1 arguemento foi digitado
		set_process(2);
		set_file_name(argv[1]);	
	}
}

void SnakeGame::process(){

	if(get_process() == GameProcess::REPORTED_FILE){

		file.open(get_file_name());

		if(file.is_open()){

			set_status(2);
			getline(file, temp);

		}else{

			set_status(1);
		}
	}
}

void SnakeGame::update(){
	
	if(get_process() == GameProcess::UNINFORMED_FILE){
		set_status(1);
	}else if(get_process() == GameProcess::FILE_DIDNT_OPEN){
		set_status(1);
	}
}

void SnakeGame::render(){

	if(get_process() == GameProcess::UNINFORMED_FILE){
		std::cout << "Name file uniformed" << std::endl;
	}else if(get_process() == GameProcess::FILE_DIDNT_OPEN){
		std::cout << "File did not open" << std::endl;
	}
}

bool SnakeGame::game_over(){

	return get_status() == GameStatus::EXIT_GAME;

}
