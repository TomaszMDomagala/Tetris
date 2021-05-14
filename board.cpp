#include "board.h"

#include <iostream>

Board::Board (int speed) {
    this -> speed = speed;

    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++){
            cells[col][row].empty = true;
            cells[col][row].floating = false;
        }
    }
}

void Board::fall() {
    for (int col = width - 1; col >= 0; col--) {
        for (int row = height - 1; row >= 0; row--){
            if (cells[col][row].empty == false && cells[col][row].floating == true && cells[col][row + 1].empty == true) {
                cells[col][row].empty = true;
                cells[col][row].floating = false;
                cells[col][row + 1].empty = false;
                cells[col][row + 1].floating = true;
            }
        }
    }
}

void Board::createpiece(int type) {

    if (type == 1) {
        // Tetrimino „I”
        for (int I = 0; I < 4; I++) {
            cells[(width/2 + 2) - I][0].floating = true;
            cells[(width/2 + 2) - I][0].empty = false;
        }

    } else if (type == 2) {
        // Tetrimino „T”
        for (int T = 0; T < 3; T++) {
            cells[(width/2 + 1)- T][0].floating = true;
            cells[(width/2 + 1)- T][0].empty = false;
        }
        cells[width/2][1].floating = true;
        cells[width/2][1].empty = false;

    } else if (type == 3) {
        // Tetrimino „O"
        for (int O = 0; O < 2; O++) {
            cells[width/2 - 1][O].floating = true;
            cells[width/2 - 1][O].empty = false;
        }
        for (int O = 0; O < 2; O++) {
            cells[width/2][O].floating = true;
            cells[width/2][O].empty = false;
        }
    } else if (type == 4) {
        // Tetrimino „L"
        for (int L = 0; L < 3; L++) {
            cells[width/2][L].floating = true;
            cells[width/2][L].empty = false;
        }
        cells[width/2 + 1][2].floating = true;
        cells[width/2 + 1][2].empty = false;

    } else if (type == 5) {
        // Tetrimino „J"
        for (int J = 0; J < 3; J++) {
            cells[width/2][J].floating = true;
            cells[width/2][J].empty = false;
        }
        cells[width/2 - 1][2].floating = true;
        cells[width/2 - 1][2].empty = false;

    } else if (type == 6) {
        // Tetrimino „S"
        for (int S = 0; S < 2; S++) {
            cells[(width/2 + 1) - S][0].floating = true;
            cells[(width/2 + 1) - S][0].empty = false;
        }
        for (int S = 0; S < 2; S++) {
            cells[width/2 - S][1].floating = true;
            cells[width/2 - S][1].empty = false;
        }

    } else if (type == 7) {
        // Tetrimino „Z"
        for (int Z = 0; Z < 2; Z++) {
            cells[width/2 - Z][0].floating = true;
            cells[width/2 - Z][0].empty = false;
        }
        for (int Z = 0; Z < 2; Z++) {
            cells[(width/2 + 1) - Z][1].floating = true;
            cells[(width/2 + 1) - Z][1].empty = false;
        }

    } else {
        std::cout << "There is no piece like that";
    }
}

void Board::collisions() {
    for (int col = 0; col < width; col++)
        if (cells[col][19].floating == true) {
            cells[col][19].floating = false;
        }

    for (int row = height; row >= 0; row--) {
        for (int col = width; col >= 0; col--) {
            if (cells[col][row + 1].empty == false && cells[col][row + 1].floating == false) {
                cells[col][row].floating = false;
//                stop_all();
            }
        }
    }

    for (int row = 0; row < height; row++) {
        if (checktetris(row) == true) {
            for (int col = 0; col < width; col++) {
                cells[col][row].empty = true;
            }
            for (int i = 0; i < width; i++) {
                for (int j = row; j >= 0; j--) {
                    if (cells[i][j].empty == false) {
                        cells[i][j].floating = true;
                    }
                }
            }
        }
    }
}

void Board::display() {
    for (int i = 0; i < 10; i++) {
        std::cout << '-';
    }
    std::cout << '\n';
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 10; col++) {
            if (cells[col][row].empty == false) {
                std::cout << 'X';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}

void Board::move(int x) {
    if (x == 1) {
        for (int row = 0; row < height; row++) {
            if (cells[0][row].floating == true && cells[0][row].empty == false) {
                return;
            }
        }
        for (int col = 1; col < width; col++) {
            for (int row = 1; row < height; row++) {
                if (cells[col][row].floating == true) {
                    cells[col - 1][row].floating = true;
                    cells[col - 1][row].empty = false;
                    cells[col][row].empty = true;
                    cells[col][row].floating = false;
                }
            }
        }
    } else if (x == 2) {
        for (int row = 0; row < height; row++) {
            if (cells[9][row].floating == true && cells[9][row].empty == false) {
                return;
            }
        }
        for (int col = width -1; col >= 0; col--) {
            for (int row = height -1; row >= 0; row--) {
                if (cells[col][row].floating == true) {
                    cells[col + 1][row].floating = true;
                    cells[col + 1][row].empty = false;
                    cells[col][row].empty = true;
                    cells[col][row].floating = false;
                }
            }
        }
    } else {
        std::cout << "There is no move like that";
    }
}

bool Board::is_empty(int col, int row) {
    if (cells[col][row].empty == false) {
        return false;
    } else {
        return true;
    }
}

bool Board::checktetris(int row) {
    for (int col = 0; col < width; col++) {
        if (cells[col][row].empty != cells[0][row].empty) {
            return false;
        }
    }
    score++;
    return true;
}

bool Board::is_over() {
    for (int col = 0; col < width; col++) {
        if (cells[col][0].floating == false && cells[col][0].empty == false) {
            return true;
        }
    }
    return false;
}

int Board::getscore() {
    return score;
}
