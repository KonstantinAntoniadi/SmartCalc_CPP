cmake_minimum_required(VERSION 3.21)
project(C2_s21_stringplus_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(testpolish
        src/s21_smartcalc/stack/stack.c
        src/s21_smartcalc/backend/s21_validator.c
        src/s21_smartcalc/backend/s21_calculate.c
        src/s21_smartcalc/backend/s21_smartcalc.c
        src/s21_smartcalc/backend/s21_getPostfix.c
        src/s21_smartcalc/backend/s21_validateFunc.c
        src/s21_smartcalc/backend/s21_validateOperator.c
        src/s21_smartcalc/backend/test.c)



#code-samples/s21_strlen.c
#src/s21_string.c
#src/s21_string.h
