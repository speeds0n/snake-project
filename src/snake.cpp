#include "../lib/snake.h"

/// Class Snake ///
Snake::Snake(){
	m_life = 5;
	m_size = 1;
}

void Snake::loss_life(){
	m_life--;
}

/// Class Player ///

void Player::set_position_x(int value){
	m_position_x = value;
}
void Player::set_position_y(int value){
	m_position_y = value;
}

void Player::set_line(int value){
	m_line = value;
}

void Player::set_colmn(int value){
	m_colmn = value;
}

void Player::set_point_x(int value){
	m_point_x = value;
}

void Player::set_point_y(int value){
	m_point_y = value;
}
Player::Direction Player::next_move(){
	Direction aux;
	aux.x = m_solution.front().x;
	aux.y = m_solution.front().y;
	m_solution.pop_front();
	return aux;
}
// solve deve rebecer a do spawn
void Player::solve(int x, int y){
	if(find_solution(m_maze, x, y)){
		//GERAR UMA NOVA COMIDA
	}else{
		std::cout << "teste" << std::endl;
		std::cout << "teste" << std::endl;
		std::cout << "teste" << std::endl;
		std::cout << "teste" << std::endl;
	}
}

bool Player::find_solution(std::deque<std::string> maze, int x, int y){

//	CurrentDir cdir;
	if(maze[x][y] == 'x'){
		return true;
	}
	if(maze[x][y] == '#' || maze[x][y] == '$' || maze[x][y] == '.'){
		return false;
	}
	maze[x][y] = '$';
	Direction dir = {x, y};
	m_solution.push_back(dir);

	bool result;

	result = find_solution(maze, x, y+1);
	if(result){	
		return true;
	}
	result = find_solution(maze, x-1, y);
	if(result){
		return true;
	}
	result = find_solution(maze, x, y-1);
	if(result){
		return true;
	}
	result = find_solution(maze, x+1, y);
	if(result){
		return true;
	}

	maze[x][y] = ' ';
	return false;
}

void Player::add_line(std::string value){
	m_maze.push_back(value);
}

void Player::print_maze(){

	int i{0}, j{0};

	while(i < get_line()){
		j = 0;
		while(j < get_colmn()){
			if(i == get_position_x() && j == get_position_y()){
				std::cout << ">";
			}else{
				std::cout << m_maze[i][j];
			}
			j++;
		}
		std::cout << std::endl;
		i++;
	}
}

void Player::delete_maze(){
	m_maze.clear();
	set_line(0);
	set_colmn(0);
}

void Player::generate_food(){

	int point_x, point_y;
	bool aux = false;

	srand(time(NULL));
	while(!aux){
		point_x = rand() % get_line();
		point_y = rand() % get_colmn();
			if(m_maze[point_x][point_y] == ' '){
			set_point_x(point_x);
			set_point_y(point_y);
			aux = true;
		}
	}
	m_maze[point_x][point_y] = 'x';
}

void Player::delete_food(int x, int y){
	m_maze[x][y] = ' ';
}

void Player::delete_solve(){
	m_solution.clear();
}
/// Class Level ///
void Level::set_line(int value){
	m_line = value;
}

void Level::set_colmn(int value){
	m_colmn = value;
}

void Level::set_spawn_x(int value){
	m_spawn_x = value;
}

void Level::set_spawn_y(int value){
	m_spawn_y = value;
}

void Level::add_line(std::string value){
	m_maze.push_back(value);
}

void Level::delete_maze(){
	m_maze.clear();
	set_line(0);
	set_colmn(0);
}

void Level::print_maze(){

	int i{0}, j{0};

	while(i < get_line()){
		j = 0;
		while(j < get_colmn()){

			if(m_maze[i][j] == '$'){
				std::cout << " ";
			}else{
				std::cout << m_maze[i][j];
			}
			j++;
		}
		std::cout << std::endl;
		i++;
	}
}

bool Level::check_spawn(){

	int i{0}, j{0};
	
	while(i < get_line()){
		j = 0;
		while(j < get_colmn()){
			if(m_maze[i][j] == '*'){
				set_spawn_x(i);
				set_spawn_y(j);
				return true;
			}
			j++;
		}
		i++;
	}
	return false;
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

void SnakeGame::set_points(int value){
	m_points = value;
}

void SnakeGame::add_point(){
	int aux = get_points();
	set_points(aux+1);
}

void SnakeGame::set_score(int value){
	m_score = value;
}

void SnakeGame::add_score(){
	int aux = get_score();
	set_score(aux+75);
}

void SnakeGame::initialize_game(int argc, char *argv[]){

	if(argc == 1){ // Apenas o ./a.out foi digitado
		set_process(1);
	}else if(argc == 2){ // executavel + 1 arguemento foi digitado
		set_process(2);
		set_file_name(argv[1]);	
	}
}

void SnakeGame::open_file(std::ifstream &file){

	file.open(get_file_name());
}

void SnakeGame::read_file(std::ifstream &file){
	
	int i{0};

	if(file.eof()){
		set_process(5);
	}else{
		getline(file, m_line);
		std::cout << m_line << std::endl;
		while(i < m_line.size()){
			if(m_line.compare(i, 1, " ") == 0){
				
				m_temp = m_line.substr(0, i);
				m_level.set_line(std::stoi(m_temp));
				m_temp = m_line.substr(i+1, m_line.size());
				m_level.set_colmn(std::stoi(m_temp));
			}
			i++;
		}

		i = 0;
		while(i < m_level.get_line()){
			getline(file, m_line);
			m_level.add_line(m_line);
			m_player.add_line(m_line);
			i++;
		}
	}
}

void SnakeGame::process(){

	if(get_process() == GameProcess::REPORTED_FILE){

		open_file(m_file);

		if(m_file.is_open()){
			// FILE OPEN
			set_process(4);

		}else{
			// FILE DID NOT OPEN
			set_process(3);
		}
	}else if(get_process() == GameProcess::CURRENT_LEVEL){
		if(m_player.solution_size() > 0){

			auto dir = m_player.next_move();
			m_player.set_position_x(dir.x);
			m_player.set_position_y(dir.y);

		}else{

			int aux_point_x = m_player.get_point_x();
			int aux_point_y = m_player.get_point_y();
			m_player.delete_solve();
			m_player.delete_food(m_player.get_point_x(), m_player.get_point_y());
			m_player.generate_food();
			m_player.solve(aux_point_x, aux_point_y);

			if(get_points() < 4){
				add_point();
				add_score();
			}else{
				set_process(7);
				set_points(0);
			}
		}

	}
}

void SnakeGame::update(){
	
	std::string temp;
	if(get_process() == GameProcess::UNINFORMED_FILE){

		set_status(1);

	}else if(get_process() == GameProcess::FILE_DIDNT_OPEN){

		set_status(1);

	}else if(get_process() == GameProcess::FILE_OPEN){
		read_file(m_file);
		set_status(2);
		if(m_level.check_spawn()){
			m_player.set_position_x(m_level.get_spawn_x());
			m_player.set_position_y(m_level.get_spawn_y());
			m_player.set_line(m_level.get_line());
			m_player.set_colmn(m_level.get_colmn());
			m_player.generate_food();
			m_player.solve(m_level.get_spawn_x(), m_level.get_spawn_y());
			set_points(0);
			set_score(0);
			set_process(9);
		}else{
			set_process(8);
		}

	}else if(get_process() == GameProcess::END_OF_FILE){

		getline(std::cin, temp);
		m_file.close();
		set_status(1);

	}else if(get_process() == GameProcess::CURRENT_LEVEL){

		set_status(2);
		std::chrono::milliseconds dura(1000/15);
		std::this_thread::sleep_for(dura);

	}else if(get_process() == GameProcess::NEXT_LEVEL){

		set_process(11);
		set_status(2);

		if(m_file.eof()){
			set_process(5);
		}
	}else if(get_process() == GameProcess::NO_FOUND_SPAWN){
		set_process(7);
	}else if(get_process() == GameProcess::WELCOME_MSG){		
		getline(std::cin, temp);
		set_process(6);
	}else if(get_process() == GameProcess::START_GAME){
		read_file(m_file);
		set_status(2);
		if(m_level.check_spawn()){
			m_player.set_position_x(m_level.get_spawn_x());
			m_player.set_position_y(m_level.get_spawn_y());
			m_player.set_line(m_level.get_line());
			m_player.set_colmn(m_level.get_colmn());
			m_player.generate_food();
			m_player.solve(m_level.get_spawn_x(), m_level.get_spawn_y());
			set_points(0);
			set_process(6);
		}else{
			set_process(8);
		}
	}else if(get_process() == GameProcess::GO_TO_NEXT_LEVEL){
		getline(std::cin, temp);
		m_level.delete_maze();
		m_player.delete_maze();
		m_player.delete_solve();

		set_process(10);
		set_status(2);

		if(m_file.eof()){
			set_process(5);
		}
	}
}

void SnakeGame::render(){

	if(get_process() == GameProcess::UNINFORMED_FILE){

		std::cout << "+------------------------------------+" << std::endl;
		std::cout << "|         Name file uniformed!       |" << std::endl;
		std::cout << "+------------------------------------+" << std::endl;

	}else if(get_process() == GameProcess::FILE_DIDNT_OPEN){

		std::cout << "+------------------------------------+" << std::endl;
		std::cout << "|          File did not open         |" << std::endl;
		std::cout << "+------------------------------------+" << std::endl;

	}else if(get_process() == GameProcess::FILE_OPEN){

	}else if(get_process() == GameProcess::CURRENT_LEVEL){

		int aux{0};
		while(aux < 40){
			std::cout << std::endl;
			aux++;
		}
		std::cout << "Lives: ";
		aux = 0;
		while(aux < m_snake.get_life()){
			std::cout << "x ";
			aux++;
		}
		std::cout << "| Score: "<< get_score() << " ";
		std::cout << "| Food eaten: " << get_points() << " of 5";
		std::cout << std::endl;
		std::cout << "________________________________________________" << std::endl;
		m_player.print_maze();

	}else if(get_process() == GameProcess::NEXT_LEVEL){

	}else if(get_process() == GameProcess::NO_FOUND_SPAWN){

		std::cout << "+------------------------------------+" << std::endl;
		std::cout << "|Spawn not found, going to next level|" << std::endl;
		std::cout << "+------------------------------------+" << std::endl;

	}else if(get_process() == GameProcess::WELCOME_MSG){

		std::cout << "---> Welcome to the classic Snake Game <---" << std::endl;
		std::cout << "     Copyright Edson Cassiano 2020" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << "Level loaded: | ";
		std::cout << "Snake lives: " << m_snake.get_life() << " | ";
		std::cout << "Apples to eat: 5" << std::endl;
		std::cout << "Clear all levels to win the game. Good luck!!!" << std::endl;
		std::cout << "--------------------------------------------------" << std::endl;
		std::cout << ">>> Press <ENTER> to start the game!" << std::endl;

	}else if(get_process() == GameProcess::END_OF_FILE){

		std::cout << "+------------------------------------+" << std::endl;
		std::cout << "|    CONGRATULATIONS anaconda WON!   |" << std::endl;
		std::cout << "|        Thanks for playing!         |" << std::endl;
		std::cout << "+------------------------------------+" << std::endl;
	}else if(get_process() == GameProcess::GO_TO_NEXT_LEVEL){

		std::cout << "+------------------------------------+" << std::endl;
		std::cout << "| Press <ENTER> to go to next level! |" << std::endl;
		std::cout << "+------------------------------------+" << std::endl;
	}
}

bool SnakeGame::game_over(){

	return get_status() == GameStatus::EXIT_GAME;
}
