#ifndef TICTACTOE_CELL_H
#define TICTACTOE_CELL_H

static const int DEFAULT_USER = 0;

class Cell {
private:
    int owner;
public:

    struct CellStepReport {
        bool done;
        std::string msg;
    };

    explicit Cell();

    [[nodiscard]] int getOwner() const;

    [[nodiscard]] CellStepReport setOwner(int newOwner);
};


#endif //TICTACTOE_CELL_H
