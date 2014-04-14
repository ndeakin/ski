# Various file directory definitions
OBJSDIR = .\x64_windows
SRCDIR = .\src

# compiler and linker flags
CC = g++
CPPFLAGS = -Wall -c -o
LDFLAGS = -std=c++0x
ifdef _DEBUG
	LDFLAGS += -g
endif

UTILOBJS = $(OBJSDIR)/math_util.o

# TODO: figure out how to match all skiobjs names with $(OBJSDIR) in front of
#       each of them.
SKIOBJS = $(OBJSDIR)/game.o $(OBJSDIR)/game_object_manager.o $(OBJSDIR)/skier.o \
	$(OBJSDIR)/visible_game_object.o $(OBJSDIR)/moving_game_object.o \
    $(OBJSDIR)/moving_game_object_manager.o $(OBJSDIR)/gate.o $(OBJSDIR)/race_course.o \
    $(OBJSDIR)/sprites.o $(OBJSDIR)/error.o $(OBJSDIR)/splash_screen.o \
    $(OBJSDIR)/menu.o

SKIOBJS += $(OBJSDIR)/ski.o

ski : $(SKIOBJS) $(UTILOBJS)
	$(CC) -o $(OBJSDIR)/ski $(LDFLAGS) $(SKIOBJS) $(UTILOBJS) \
	-L SFML-2.1/lib -lsfml-graphics-d -lsfml-window-d -lsfml-system-d

$(OBJSDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) -I SFML-2.1/include $(CPPFLAGS) $@ $<

.PHONY: clean
.PHONY: clean-only

clean-only :
	rm -f $(OBJSDIR)\ski.exe 
	rm -f $(SKIOBJS)

clean : clean-only
	make
