# Various file directory definitions
OBJSDIR = .\x64_windows
SRCDIR = .\src

# compiler and compiler flags
CC = g++
CPPFLAGS = -c -o
LDFLAGS = -std=c++0x
ifdef _DEBUG
  LDFLAGS += -ggdb
endif

SKIOBJS = $(OBJSDIR)/ski.o $(OBJSDIR)/game.o $(OBJSDIR)/game_object_manager.o \
  $(OBJSDIR)/skier.o $(OBJSDIR)/visible_game_object.o

ski : $(SKIOBJS)
	$(CC) -o $(OBJSDIR)/ski $(LDFLAGS) $(SKIOBJS) \
  -L SFML-2.1/lib -lsfml-graphics -lsfml-window -lsfml-system

$(OBJSDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -I SFML-2.1/include $(CPPFLAGS) $@ $<

.PHONY: clean
.PHONY: clean-only

clean-only :
	rm -f $(OBJSDIR)\ski.exe 
	rm -f $(SKIOBJS)

clean : clean-only
	make
