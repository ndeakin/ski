ski : ski.o
	g++ -o ski ski.o game.o game_object_manager.o \
  -L SFML-2.1/lib -lsfml-graphics -lsfml-window

ski.o : ski.cpp game.hpp visible_game_object.hpp \
        game.o game_object_manager.o skier.o visible_game_object.o
	g++ -O -c ski.cpp -I SFML-2.1/include

game.o : game.cpp game.hpp
	g++ -O -c game.cpp -I SFML-2.1/include

game_object_manager.o : game_object_manager.cpp game_object_manager.hpp
	g++ -O -c game_object_manager.cpp -I SFML-2.1/include

skier.o : skier.cpp skier.hpp
	g++ -O -c skier.cpp -I SFML-2.1/include

visible_game_object.o : visible_game_object.cpp visible_game_object.hpp
	g++ -O -c visible_game_object.cpp -I SFML-2.1/include

clean :
	rm ski.exe ski.o game.o game_object_manager.o skier.o visible_game_object.o
