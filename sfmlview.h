#ifndef sfmlview_h
#define sfmlview_h

#include <SFML/Graphics.hpp>

#include "board.h"

class Sfmlview {
    sf::RectangleShape square;
    Board &board;
public:
    Sfmlview (Board &board);
    void drawOnWindow (sf::RenderWindow & win);
};

#endif //sfmlview_h
