#ifndef TICTACTOE_CONSOLEUI_H
#define TICTACTOE_CONSOLEUI_H


#include <map>
#include "UserInterface.h"

class ConsoleUI : public UserInterface {
private:
    std::map<int, char> playersSign;

public:
    using UserInterface::UserInterface;

    explicit ConsoleUI(UIListener *listener);

    void updateField(const std::vector<std::vector<Cell>>& field) override;

    void printMsg(std::string msg) override;

    void startGame() override;

    void askForStep(int player) override;

    void askFieldParams() override;

    void finishGame() override;
};


#endif //TICTACTOE_CONSOLEUI_H
