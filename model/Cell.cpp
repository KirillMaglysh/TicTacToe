#include <stdexcept>
#include "Cell.h"

int Cell::getOwner() const {
    return owner;
}

Cell::CellStepReport Cell::setOwner(int newOwner) {
    if (owner != DEFAULT_USER) {
        return {false, "step in busy cell"};
    }

    owner = newOwner;
    return {true};
}

Cell::Cell() : owner(DEFAULT_USER) {}
