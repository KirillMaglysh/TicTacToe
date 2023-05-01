#ifndef TICTACTOE_CONTROLLER_H
#define TICTACTOE_CONTROLLER_H


#include "../view/UserInterface.h"
#include "../model/Field.h"
#include "../view/UIListener.h"

class Controller : public UIListener {
private:
    int playerNumber;
    int currentPlayer;
    Field *field;
    UserInterface *ui;
public:
    Controller();

    void startGame();

    void processFieldParams(FieldParams params) override;

    void processStep(int row, int column) override;

    void processGameFinish(bool needSave) override;
};


#endif //TICTACTOE_CONTROLLER_H
