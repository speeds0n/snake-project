all:
	mkdir -p bin
	g++ -Wall -std=c++11 -c src/snake.cpp -o bin/snake.o
	g++ -Wall -std=c++11 main.cpp -C bin/snake.o -o bin/snaze
run:
	./bin/snaze data/level_5_zeros_h.dat
clear:
	rm bin/snaze
	rm bin/snake.o
	rmdir bin
