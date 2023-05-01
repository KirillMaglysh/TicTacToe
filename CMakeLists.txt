cmake_minimum_required(VERSION 3.24)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 23)

add_executable(TicTacToe main.cpp model/Field.h model/Field.cpp model/Cell.h model/Cell.cpp model/FieldStepReport.h model/FieldStepReport.cpp view/ConsoleUI.h view/ConsoleUI.cpp view/UIListener.h controller/Controller.cpp controller/Controller.h view/UserInterface.h view/UIListener.h Utils.h)
