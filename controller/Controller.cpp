#include "Controller.h"
#include "../view/ConsoleUI.h"
#include "../Utils.h"

Controller::Controller() {
    playerNumber = 2;
    currentPlayer = 1;
    ui = new ConsoleUI(this);
}

void Controller::startGame() {
    ui->startGame();
    ui->printMsg("Now lets set up the game:");
    ui->askFieldParams();
}

void Controller::processFieldParams(FieldParams params) {
    if (!isIn(params.width, MIN_FIELD_DIM, MAX_FIELD_DIM) ||
        !isIn(params.height, MIN_FIELD_DIM, MAX_FIELD_DIM) ||
        !isIn(params.height, MIN_FIELD_DIM, std::min(params.height, params.width))) {
        ui->printMsg("Sorry, values are incorrect, please, try again.");
        ui->askFieldParams();
        return;
    }

    field = new Field(params);
    ui->updateField(field->getField());
    ui->askForStep(currentPlayer);
}

void Controller::processStep(int row, int column) {
    FieldStepReport *report = field->makeStep(row, column, currentPlayer);
    switch (report->type) {
        case FieldStepReport::INCORRECT:
            ui->printMsg("Incorrect step: " + report->msg);
            ui->askForStep(currentPlayer);
            break;
        case FieldStepReport::WIN:
            ui->printMsg("Player " + std::to_string(currentPlayer) + " won");
            processGameFinish(false);
            break;
        case FieldStepReport::DRAW:
            ui->printMsg("Draw");
            processGameFinish(false);
            break;
        case FieldStepReport::CONTINUE:
            ++currentPlayer;
            if (currentPlayer == playerNumber + 1) {
                currentPlayer = 1;
            }
            ui->updateField(field->getField());
            ui->askForStep(currentPlayer);
            break;
    }
}

void Controller::processGameFinish(bool needSave) {
    ui->finishGame();
    exit(0);
}
