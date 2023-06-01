#pragma once

#include "controllercalculator.h"

namespace s21 {
    double ControllerCalculator::Calculate(const std::string &infix, const double x) {
        Expression expression(infix);

        return expression.Calculate(0);
    }

};