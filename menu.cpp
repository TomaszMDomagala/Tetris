#include "menu.h"
#include <iostream>

void Menu::display() {
    sf::RenderWindow win(sf::VideoMode(menu_screen_width, menu_screen_height), "Space Invaders");
    win.setVerticalSyncEnabled(true);

    while(win.isOpen()) {
        sf::Event event;

        win.clear(sf::Color(0, 0, 0));
        drawOnWindow(win);
        win.display();

        int xmouse = 0, ymouse = 0;

        while(win.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                win.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
    			if (event.mouseButton.button == sf::Mouse::Left) {
    				xmouse = event.mouseButton.x;
                    ymouse = event.mouseButton.y;
        		}

                if (xmouse > 50 && xmouse < menu_screen_width - 50 ) {
                    if (ymouse > 100 && ymouse < 100 + menu_screen_height/5) {
                        option = 1;
                    }
                    if (ymouse > 300 && ymouse < 300 + menu_screen_height/5) {
                        option = 2;
                    }
                }
            }
        }
        if (option != 0) {
            win.close();
        }
    }
}

void Menu::drawOnWindow(sf::RenderWindow & win) {

    sf::Font font;
    if (!font.loadFromFile("./VeraSe.ttf")) {
        std::cout << "Error";
    }

    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(3);
    text.setCharacterSize(30);
    text.setPosition(menu_screen_width/2 - 50, 30);
    text.setString("Tetris");
    win.draw(text);

    sf::RectangleShape square;
    square.setSize(sf::Vector2f(menu_screen_width - 100, menu_screen_height/5));
    square.setPosition(50, 100);
    square.setFillColor(sf::Color(219, 252, 3));
    win.draw(square);

    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(menu_screen_width/2 - 35, 120);
    text.setString("Play");
    win.draw(text);

    square.setSize(sf::Vector2f(menu_screen_width - 100, menu_screen_height/5));
    square.setPosition(50, 300);
    square.setFillColor(sf::Color(252, 28, 3));
    win.draw(square);

    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setPosition(menu_screen_width/2 - 30, 320);
    text.setString("Exit");
    win.draw(text);

}

int Menu::getoption() {
    return option;
}
