#include <stdio.h>
#include <stdint.h>

#define MAX_FIB_INDEX 100
intmax_t prevFib[MAX_FIB_INDEX + 1];

intmax_t fib_i_core(int userInput) {
    intmax_t number1 = 0;
    intmax_t number2 = 1;
    intmax_t result = 0;

    if (userInput == 0) {
        return 0;
    } else if (userInput == 1) {
        return 1;
    }

    for (int i = 2; i <= userInput; i++) {
        result = number1 + number2;
        number1 = number2;
        number2 = result;
    }
    return number2;
}

intmax_t fib_i(int userInput) {
    for (int i = 0; i <= MAX_FIB_INDEX; i++) {
        prevFib[i] = -1;
    }

    if (prevFib[userInput] != -1) {
        return prevFib[userInput];
    }

    prevFib[userInput] = fib_i_core(userInput);
    return prevFib[userInput];
}

intmax_t fib_r_core(int userInput) {
    if (userInput == 0) {
        return 0;
    }
    if (userInput == 1) {
        return 1;
    }
    return fib_r_core(userInput - 1) + fib_r_core(userInput - 2);
}

intmax_t fib_r(int userInput) {
    if (prevFib[userInput] != -1) {
        return prevFib[userInput];
    }

    if (userInput == 0) {
        prevFib[userInput] = 0;
    } else if (userInput == 1) {
        prevFib[userInput] = 1;
    } else {
        prevFib[userInput] = fib_r(userInput - 1) + fib_r(userInput - 2);
    }

    return prevFib[userInput];
}

int main(int argc, char *argv[]) {
    int userInput;
    char input = argv[2][0]; 
    
    sscanf(argv[1], "%d", &userInput);
    userInput -= 1;

    for (int i = 0; i <= MAX_FIB_INDEX; i++) {
        prevFib[i] = -1;
    }

    intmax_t result = 0;

    if (input == 'i') {
        result = fib_i(userInput);
    } else if (input == 'r') {
        result = fib_r(userInput);
    }

    printf("%jd\n", result);
    return 0;
}
