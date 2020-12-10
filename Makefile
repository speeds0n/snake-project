all:
	g++ -Wall -std=c++11 -c src/snake.cpp -o snake.o
	g++ -Wall -std=c++11 main.cpp -C snake.o
