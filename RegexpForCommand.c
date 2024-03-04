//
// Created by teller on 04.03.2024.
//
#include "RegexpForCommand.h"
#include <C:\tools\GnuWin32\include\regex.h>
#include <stdio.h>

const char *cregexMovi = "MOVI[\\s]+[\\d]+";

int getCommandsCode(char *buffer, size_t bufSize) {
    int res;
    regex_t regex;
    regcomp(&regex, buffer, 0);
    res = regexec(&regex, buffer, 0, NULL, 0);
    if (res == 0) {
        printf("MOVI found");
    }
    if (res == REG_NOMATCH) {
        printf("MOVI not found");
    }
    regfree(&regex);
    return 0;
}