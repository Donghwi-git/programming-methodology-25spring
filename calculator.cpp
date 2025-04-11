#include "calculator.h"
#include <stdexcept>

#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

int Calculator::add(int a, int b) {
    if (b > 0 && a > INT_MAX - b) {
        throw std::overflow_error("Addition overflow");
    }
    if (b < 0 && a < INT_MIN - b) {
        throw std::overflow_error("Addition underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if (b < 0 && a > INT_MAX + b) {
        throw std::overflow_error("Subtraction overflow");
    }
    if (b > 0 && a < INT_MIN + b) {
        throw std::overflow_error("Subtraction underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0 && a > INT_MAX / b) {
            throw std::overflow_error("Multiplication overflow");
        }
        if (b < 0 && b < INT_MIN / a) {
            throw std::overflow_error("Multiplication underflow");
        }
    } else if (a < 0) {
        if (b > 0 && a < INT_MIN / b) {
            throw std::overflow_error("Multiplication underflow");
        }
        if (b < 0 && a < INT_MAX / b) {
            throw std::overflow_error("Multiplication overflow");
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == INT_MIN && b == -1) {
        // special overflow case: -INT_MIN overflows
        throw std::overflow_error("Division overflow");
    }
    return a / b;
}