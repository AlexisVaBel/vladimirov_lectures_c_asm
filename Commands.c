//
// Created by teller, story teller on 04.03.2024.
//
#include <stdio.h>
#include "Commands.h"
#include "Registers.h"


void getStringForMOVI(int value, char *buffer, size_t bufSize) {
    int result = snprintf(buffer,bufSize,"MOVI %d\n",value);
}

void getStringForIOCommand(int value, char *buffer, size_t bufSize) {
    int destRegister = value & 0x3;
    char *destName = getRegisterName(destRegister);
    if (destName == NULL) {
        return;
    }
    int command = value >> 0x2;
    if (command & IN) {
        int result = snprintf(buffer,bufSize,"IN %s\n", destName);
        return;
    }
    if (command & OUT) {
        int result = snprintf(buffer,bufSize,"OUT %s\n", destName);
        return;
    }
}

void getStringForMathCommand(int value, char *buffer, size_t bufSize) {
    int sourceRegister = value;
    sourceRegister = (sourceRegister >> 2) & 0x3;
    int destRegister = value & 0x3;

    int command = value >> 0x4;
    char *destName = getRegisterName(destRegister);
    char *srcName = getRegisterName(sourceRegister);
    if (destName == NULL
        || srcName == NULL) {
        return;
    }
    if (command == ADD) {
        int result = snprintf(buffer,bufSize,"ADD %s, %s\n", srcName, destName);
        return;
    }
    if (command == SUB) {
        int result = snprintf(buffer,bufSize,"SUB %s, %s\n", srcName, destName);
        return;
    }
    if (command == MUL) {
        int result = snprintf(buffer,bufSize,"MUL %s, %s\n", srcName, destName);
        return;
    }
    if (command == DIV) {
        int result = snprintf(buffer,bufSize,"DIV %s, %s\n", srcName, destName);
        return;
    }
}


void getStringForBinaryCommand(int value, char *buffer, size_t bufSize) {
    int commandType = value >> 6;

    if ((commandType & 0b10) == 0) {
        getStringForMOVI(value, buffer,  bufSize);
        return;
    }
    if ((commandType & 0b11) == 0b10) {
        getStringForMathCommand(value, buffer,  bufSize);
        return;
    }
    if ((commandType & 0b11) == 0b11) {
        getStringForIOCommand(value, buffer,  bufSize);
        return;
    }
}


void printVICommand(int value) {
    printf("MOVI %d\n", value);
}

void printIOCommand(int value) {
    int destRegister = value & 0x3;
    char *destName = getRegisterName(destRegister);
    if (destName == NULL) {
        return;
    }
    int command = value >> 0x2;
    if (command & IN) {
        printf("IN %s\n", destName);
        return;
    }
    if (command & OUT) {
        printf("OUT %s\n", destName);
        return;
    }
}


void printMathCommand(int value) {
    int sourceRegister = value;
    sourceRegister = (sourceRegister >> 2) & 0x3;
    int destRegister = value & 0x3;

    int command = value >> 0x4;
    char *destName = getRegisterName(destRegister);
    char *srcName = getRegisterName(sourceRegister);
    if (destName == NULL
        || srcName == NULL) {
        return;
    }
    if (command == ADD) {
        printf("ADD %s, %s\n", srcName, destName);
        return;
    }
    if (command == SUB) {
        printf("SUB %s, %s\n", srcName, destName);
        return;
    }
    if (command == MUL) {
        printf("MUL %s, %s\n", srcName, destName);
        return;
    }
    if (command == DIV) {
        printf("DIV %s, %s\n", srcName, destName);
        return;
    }
}

void printCommandByValue(int value) {
    int commandType = value >> 6;

    if ((commandType & 0b10) == 0) {
        printVICommand(value);
        return;
    }
    if ((commandType & 0b11) == 0b10) {
        printMathCommand(value);
        return;
    }
    if ((commandType & 0b11) == 0b11) {
        printIOCommand(value);
        return;
    }

}

