//
// Created by teller on 04.03.2024.
//

#pragma once

#include <stdlib.h>

enum Register {
    A = 0,
    B = 1,
    C = 2,
    D = 3,
};


char *getRegisterName(int value) {
    switch (value) {
        case A:
            return "A";
        case B:
            return "B";
        case C:
            return "C";
        case D:
            return "D";
    }
    return NULL;
}
