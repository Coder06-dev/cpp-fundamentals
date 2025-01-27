#pragma once

int fibonacci_iterative(int sequence) {
    int result = 0;
    int j = 0;
    int k = 1;
    if (sequence == 0 || sequence == 1)
        return sequence;
    else {
        for (int i = 2; i <= sequence; i++) {
            result = j + k;
            j = k;
            k = result;
        }
    }
    return result;
}

int fibonacci_recursive(int sequence) {
    if (sequence == 0 || sequence == 1)
        return sequence;
    else {
        return (fibonacci_recursive(sequence - 1) + fibonacci_recursive(sequence - 2));
    }
}
