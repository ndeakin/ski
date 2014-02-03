ski
===

This is (going to be) an arcade skiing game. You are a skier competing in the 
winter olympics and must earn pride for your country!


The Code base
************

The game currently consists of ski.cpp, where execution starts right before
going into game.cpp (which has an associated header, game.hpp).  game.cpp
usese instances of the classes declared in game_object_manager.hpp and
skier.hpp (and their associated .cpp files).  Last but not least, the Skier
class derives from the Visible_game_object class, declared and derived in
its similarly named .hpp and .cpp files.  The SFML-2.1 directory contains the
the SFML media library that the project uses.


Future Development
******************

The game is not currently functional, as of writing this on january 30, 2014.
The first 4 classes and an execution function have been created as a base
to work from.  The next goals are to get a window showing some sprites, and
then to refine those sprite images.
