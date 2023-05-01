#include "Field.h"

FieldStepReport *Field::makeStep(int row, int column, int player) {
    if (!checkBorders(row, column)) {
        return new FieldStepReport(FieldStepReport::INCORRECT, "The cell is out of field");
    }

    Cell::CellStepReport cellReport = field[row][column].setOwner(player);
    if (!cellReport.done) {
        return new FieldStepReport(FieldStepReport::INCORRECT, cellReport.msg);
    }

    FieldStepReport *winState = checkWin(row, column);
    if (winState->type == FieldStepReport::WIN) {
        return winState;
    }

    if (isDraw()) {
        return new FieldStepReport(FieldStepReport::DRAW);
    }

    return new FieldStepReport(FieldStepReport::CONTINUE);
}

bool Field::checkBorders(int row, int column) const {
    return row >= 0 && row < params.height && column >= 0 && column < params.width;
}

bool Field::isDraw() const {
    return filledNumber == params.height * params.width;
}

FieldStepReport *Field::checkWin(int row, int column) const {
    std::pair<int, int> res =
            scan(row - std::min(params.targetLen, std::min(row, column)),
                 column - std::min(params.targetLen, std::min(row, column)),
                 1, 1);
    if (res.first != -1) {
        return new WINFieldStepReport(
                res.first,
                res.second,
                WINFieldStepReport::LEFT_UP_TO_RIGHT_DOWN);
    }

    res = scan(row + std::min(params.targetLen, std::min(params.height - row - 1, column)),
               column - std::min(params.targetLen, std::min(row, column)),
               -1, 1);
    if (res.first != -1) {
        return new WINFieldStepReport(res.first,
                                      res.second,
                                      WINFieldStepReport::LEFT_DOWN_TO_RIGHT_UP);
    }

    res = scan(row,
               column - std::min(params.targetLen, column),
               0, 1);
    if (res.first != -1) {
        return new WINFieldStepReport(res.first,
                                      res.second,
                                      WINFieldStepReport::LEFT_TO_RIGHT);
    }

    res = scan(row + std::min(params.targetLen, params.height - row - 1),
               column,
               -1, 0);
    if (res.first != -1) {
        return new WINFieldStepReport(res.first,
                                      res.second,
                                      WINFieldStepReport::DOWN_TO_UP);
    }

    return new FieldStepReport(FieldStepReport::CONTINUE);
}

std::pair<int, int> Field::scan(int row, int column, int rowShift, int columnShift) const {
    int lenGot = 1;
    std::pair<int, int> start = {-1, -1};
    for (int i = 1; checkBorders(row + i * rowShift, column + i * columnShift); ++i) {
        if (field[row + i * rowShift][column + i * columnShift].getOwner() != DEFAULT_USER &&
            field[row + i * rowShift][column + i * columnShift].getOwner() ==
            field[row + (i - 1) * rowShift][column + (i - 1) * columnShift].getOwner()) {
            ++lenGot;

            if (lenGot == params.targetLen) {
                start = {row + i * rowShift - params.targetLen * rowShift + 1,
                         column + i * columnShift - params.targetLen * columnShift + 1};
                break;
            }
        } else {
            lenGot = 1;
        }
    }

    return start;
}

Field::Field(FieldParams params) : params(params) {
    filledNumber = 0;
    field.resize(params.height, std::vector<Cell>(params.width, Cell()));
}

const std::vector<std::vector<Cell>>& Field::getField() const {
    return field;
}

FieldParams::FieldParams(int height, int width, int targetLen) : height(height), width(width), targetLen(targetLen) {}
