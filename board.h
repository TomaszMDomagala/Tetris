#ifndef board_h
#define board_h

#include <vector>

struct cell {
    bool empty;
    bool floating;
};

class Board {
    const int height = 20;
    const int width = 10;
    cell cells[10][20];
    int speed;
    int score = 0;
public:
    Board(int speed);
    void fall();
    void createpiece(int type);
    void collisions();
    void display();
    void move(int x);
    bool is_empty(int col, int row);
    bool checktetris(int row);
    bool is_over();
    int getscore();
};

#endif //board_h
