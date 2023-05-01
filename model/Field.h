#ifndef TICTACTOE_FIELD_H
#define TICTACTOE_FIELD_H


#include <vector>
#include <string>
#include "Cell.h"
#include "FieldStepReport.h"

struct FieldParams {
    int height;
    int width;
    int targetLen;

    FieldParams(int height, int width, int targetLen);
};

const int MIN_FIELD_DIM = 3;
const int MAX_FIELD_DIM = 9;

class Field {
private:
    std::vector<std::vector<Cell>> field;
    FieldParams params;
    int filledNumber;

    [[nodiscard]] bool checkBorders(int row, int column) const;

    [[nodiscard]] FieldStepReport *checkWin(int row, int column) const;

    [[nodiscard]] bool isDraw() const;

    [[nodiscard]] std::pair<int, int> scan(int row, int column, int rowShift, int columnShift) const;

public:
    explicit Field(FieldParams params);

    [[nodiscard]] const std::vector<std::vector<Cell>>& getField() const;

    [[nodiscard]] FieldStepReport *makeStep(int row, int column, int player);
};


#endif //TICTACTOE_FIELD_H
