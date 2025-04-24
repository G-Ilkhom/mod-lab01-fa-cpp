// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    int word_count = 0;
    bool inside_word = false;
    bool has_digit = false;

    while (*str) {
        if (!isspace(*str) && !inside_word) {
            inside_word = true;
            has_digit = false;
        }
        else if (isspace(*str) && inside_word) {
            if (!has_digit) {
                word_count++;
            }
            inside_word = false;
        }
        else if (isdigit(*str) && inside_word) {
            has_digit = true;
        }
        str++;
    }

    if (inside_word && !has_digit) {
        word_count++;
    }

    return word_count;
}

unsigned int faStr2(const char *str) {
    int valid_word_count = 0;
    bool inside_word = false;
    bool all_lower_after_first = true;
    bool first_upper = false;

    while (*str) {
        if (!isspace(*str) && !inside_word) {
            if (first_upper && all_lower_after_first) {
                valid_word_count++;
            }

            inside_word = true;
            all_lower_after_first = true;

            if (isupper(*str)) {
                first_upper = true;
            }
            else {
                first_upper = false;
            }

        }
        else if (isspace(*str) && inside_word) {
            inside_word = false;
        }
        else if (!islower(*str) && inside_word) {
            all_lower_after_first = false;
        }

        str++;
    }

    if (first_upper && all_lower_after_first) {
        valid_word_count++;
    }

    return valid_word_count;
}

unsigned int faStr3(const char *str) {
    int word_count = 0;
    double total_length = 0;
    bool inside_word = false;
    while (*str) {
        if (*str != ' ' && inside_word == false) {
            word_count++;
            total_length++;
            inside_word = true;
        }
        else if (*str != ' ' && inside_word == true) {
            total_length++;
        }
        else if (*str == ' ' && inside_word == true) {
            inside_word = false;
        }
        str++;
    }
    return round(total_length / word_count);
}
