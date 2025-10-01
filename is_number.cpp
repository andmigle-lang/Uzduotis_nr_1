#include "is_number.h"
using std::string;

bool isNumber(string s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}