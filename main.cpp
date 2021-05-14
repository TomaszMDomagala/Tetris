#include "board.h"
#include "sfmlview.h"
#include "menu.h"

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

int main () {

    srand(time(NULL));

    Menu menu;
    menu.display();

    if (menu.getoption() == 2) {
        return 0; 
    }

    constexpr int screen_width = 400;
    constexpr int screen_height = 800;
    sf::RenderWindow win(sf::VideoMode(screen_width, screen_height), "Tetris");
    win.setVerticalSyncEnabled(true);

    Board board (1);
    Sfmlview view (board);

    int i = 0;

    while(win.isOpen()) {
	    sf::Event event;
	    while(win.pollEvent(event)) {
		    if (event.type == sf::Event::Closed) {
			    win.close();
		    }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		        board.move(1);
	        }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		        board.move(2);
	        }
        }
        board.collisions();
        board.fall();
        std::system("clear");
        board.display();
        usleep(35000);
        if (i == 20) {
            board.createpiece(1 +rand() % 7);
            i = 0;
        }
        i++;
        if (board.is_over()) {
            break;
        }

        win.clear(sf::Color::Black);
        view.drawOnWindow(win);
        win.display();
    }

    std::cout << board.getscore() << '\n';

    return 0;
}
