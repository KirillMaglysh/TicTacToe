#include <iostream>
#include "ConsoleUI.h"

void ConsoleUI::updateField(const std::vector<std::vector<Cell>>& field) {
    for (const auto& row : field) {
        for (const auto& cell : row) {
            std::cout << playersSign[cell.getOwner()];
        }

        std::cout << std::endl;
    }
}

void ConsoleUI::printMsg(std::string msg) {
    std::cout << msg << std::endl;
}

void ConsoleUI::startGame() {
    printMsg("It is Tic Tak Toe!");
    printMsg("Rules are simple: you need to make line of X/0");
    printMsg(
            "To make a step you need input 2 numbers: number of the row and of the column, where you want to put you sign"
    );
}

void ConsoleUI::finishGame() {
    printMsg("Game Finished");
    printMsg("Print anything to exit");
    std::string answer;
    std::cin >> answer;
}

void ConsoleUI::askFieldParams() {
    int height;
    int width;
    int lineLength;
    printMsg("Height [3, " + std::to_string(MAX_FIELD_DIM) + "]:");
    std::cin >> height;
    printMsg("Width [3, " + std::to_string(MAX_FIELD_DIM) + "]:");
    std::cin >> width;
    printMsg("Line Length: [3, " + std::to_string(std::min(height, width)) + "]");
    std::cin >> lineLength;
    listener->processFieldParams({height, width, lineLength});
}

ConsoleUI::ConsoleUI(UIListener *listener) : UserInterface(listener) {
    playersSign[0] = '.';
    playersSign[1] = 'X';
    playersSign[2] = '0';
}

void ConsoleUI::askForStep(int player) {
    printMsg("Player " + std::to_string(player) + " steps");
    printMsg("row = ");
    int row;
    std::cin >> row;
    int column;
    printMsg("column = ");
    std::cin >> column;
    listener->processStep(row - 1, column - 1);
}
