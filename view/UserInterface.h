#ifndef TICTACTOE_USERINTERFACE_H
#define TICTACTOE_USERINTERFACE_H

#include <vector>
#include <string>
#include "../model/Cell.h"
#include "UIListener.h"

class UserInterface {
protected:
    UIListener *listener;

public:
    explicit UserInterface(UIListener *listener) : listener(listener) {}

    virtual void updateField(const std::vector<std::vector<Cell>>& field) = 0;

    virtual void printMsg(std::string msg) = 0;

    virtual void askFieldParams() = 0;

    virtual void askForStep(int player) = 0;

    virtual void startGame() = 0;

    virtual void finishGame() = 0;
};

#endif //TICTACTOE_USERINTERFACE_H
