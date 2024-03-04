//
// Created by teller on 04.03.2024.
//

#pragma once

/// variable length commands
enum Commands {
    MOVI = 0,
    ADD = 0b1000,
    SUB = 0b1001,
    MUL = 0b1010,
    DIV = 0b1011,
    IN = 0b110000,
    OUT = 0b110001,
    ERROR = 0b1111,
};

struct CommandHolder {
    enum Commands holder[8];
};

void printCommandByValue(int value);
void getStringForBinaryCommand(int value,char *buffer, size_t bufSize);