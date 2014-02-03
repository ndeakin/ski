# Various file directory definitions
OBJSDIR = x64_windows
SRCDIR = src

# compiler and compiler flags
CC = g++
#CPPFLAGS = -O

SKIOBJS = $(OBJSDIR)/ski.o $(OBJSDIR)/game.o $(OBJSDIR)/game_object_manager.o \
  $(OBJSDIR)/skier.o $(OBJSDIR)/visible_game_object.o

ski : $(SKIOBJS)
	$(CC) -o $(OBJSDIR)/ski $(SKIOBJS) \
  -L SFML-2.1/lib -lsfml-graphics -lsfml-window

$(OBJSDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -I SFML-2.1/include -c -o $@ $<

.PHONY: clean
.PHONY: clean-only

clean-only :
	rm -f $(OBJSDIR)\ski.exe 
	rm -f $(OBJSDIR)\*.o

clean : clean-only
	make
