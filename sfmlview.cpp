#include "sfmlview.h"

#include <iostream>
#include <string>

Sfmlview::Sfmlview(Board &board) : board(board) {
    square.setSize(sf::Vector2f(30, 30));
}

void Sfmlview::drawOnWindow(sf::RenderWindow & win) {
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 10; col++) {
            if (board.is_empty(col, row) == false){
                square.setFillColor(sf::Color::Blue);
                square.setPosition(col * 40, row * 40);
                win.draw(square);
            }
        }
    }
    sf::Font font;
        if (!font.loadFromFile("./VeraSe.ttf")) {
            std::cout << "Error";
        }
        sf::Text text;
        text.setFont(font);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(2);
        text.setCharacterSize(40);
        text.setPosition(15, 15);
        std::string s = std::to_string(board.getscore());
        text.setString(s);
        win.draw(text);

}
