
main: main.o loadTexture.o Bird.o Game.o Pipe.o Values.hpp
	g++ -std=c++17 -Wall main.o loadTexture.o Game.o Bird.o Pipe.o -o main -lSDL2 -lSDL2_image

main.o: main.cpp
	g++ -c -Wall main.cpp

loadTexture.o: loadTexture.cpp loadTexture.hpp
	g++ -c -Wall loadTexture.cpp

Bird.o: Bird.cpp Bird.hpp
	g++ -c -Wall Bird.cpp

Game.o: Game.cpp Game.hpp
	g++ -c -Wall Game.cpp

Pipe.o: Pipe.cpp Pipe.hpp
	g++ -c -Wall Pipe.cpp

run:
	./main

clean:
	rm -f *.o main
