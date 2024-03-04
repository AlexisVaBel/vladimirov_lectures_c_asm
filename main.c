#include <stdio.h>
#include "Commands.h"
#include "RegexpForCommand.h"

// 1. read bit sequences from input and produce text representation - ok
// 2. read text and produce code representation - todo
// 3. combine them and create calculator simulator - todo

int main() {
//    int value=0;
//    while (1 == scanf("%x", &value)) {
//        printType(value);
//    }

    char commandBuffer[64];
    getStringForBinaryCommand(0xC0,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);
    getStringForBinaryCommand(0x64,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);
    getStringForBinaryCommand(0x83,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);
    getStringForBinaryCommand(0xC1,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);
    getStringForBinaryCommand(0x03,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);
    getStringForBinaryCommand(0x87,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);
    getStringForBinaryCommand(0xA1,commandBuffer,64);
    printf("%s",commandBuffer);
    getCommandsCode(commandBuffer,64);

    printf("****************************************");
    printCommandByValue(0xC0);
    printCommandByValue(0x64);
    printCommandByValue(0x83);
    printCommandByValue(0xC1);
    printCommandByValue(0x03);
    printCommandByValue(0x87);
    printCommandByValue(0xA1);
    return 0;
}
