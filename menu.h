#ifndef menu_h
#define menu_h
#include <SFML/Graphics.hpp>

class Menu {
    const int menu_screen_height = 400;
    const int menu_screen_width = 400;
    int option = 0;
public:
    void display();
    void drawOnWindow (sf::RenderWindow & win);
    int getoption();
};

#endif //menu_h
