#Makefile

OBJS = main.o board.o sfmlview.o menu.o
CXX = clang++
CXXFLAGS = -Wall -std=c++11
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

MS: $(OBJS)
	$(CXX) -o tetris $(OBJS) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) tetris $(OBJS)
