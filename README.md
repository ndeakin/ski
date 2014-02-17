#ski

This is an arcade skiing game. You are a skier competing in the winter 
olympics and must earn pride for your country!


##How to Build

Replace the SFML-2.1 folder with the one your system requires.  You can get
the SFML library at http://www.sfml-dev.org/download/sfml/2.1/.  Copy and
paste your system's required dll files from SFML-2.1\bin into the .exe's
directory (If you aren't sure which ones, the errors will tell you what they
are called). The ones included are for windows x64 with gcc 4.7 or later.
The current Makefile should allow a person with GNU Make, windows x64, and
gcc 4.7 to compile the project as is. TODO: add build options for other
platforms to the Makefile.


##Future Development

The game currently shows a single sprite that falls down a wite background.
I think needless to say, there is work to be done. Fleshing out the graphics
(ex. having the skier change sprites) and improving physics (ex. implementing
physics) are the main priorities currently.
