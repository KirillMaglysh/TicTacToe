#ifndef TICTACTOE_UILISTENER_H
#define TICTACTOE_UILISTENER_H

#include "../model/Field.h"

class UIListener {
public:
    virtual void processFieldParams(FieldParams params) = 0;

    virtual void processStep(int row, int column) = 0;

    virtual void processGameFinish(bool needSave) = 0;
};

#endif //TICTACTOE_UILISTENER_H
