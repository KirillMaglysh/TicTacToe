#ifndef TICTACTOE_FIELDSTEPREPORT_H
#define TICTACTOE_FIELDSTEPREPORT_H


#include <string>

class FieldStepReport {
public:
    enum ReportType {
        INCORRECT,
        WIN,
        DRAW,
        CONTINUE
    };

    ReportType type;
    std::string msg;

    explicit FieldStepReport(ReportType type, std::string msg = "");
};

class WINFieldStepReport : public FieldStepReport {
public:
    enum DIR {
        LEFT_TO_RIGHT,
        DOWN_TO_UP,
        LEFT_UP_TO_RIGHT_DOWN,
        LEFT_DOWN_TO_RIGHT_UP
    };

    int row;
    int column;
    DIR dir;

    WINFieldStepReport(const std::string& msg, int row, int column, DIR dir);
    WINFieldStepReport(int row, int column, DIR dir);
};

#endif //TICTACTOE_FIELDSTEPREPORT_H
