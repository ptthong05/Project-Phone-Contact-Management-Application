#ifndef PHONEVALIDATOR_H
#define PHONEVALIDATOR_H

#include <string>
#include <cctype>
using namespace std;

class PhoneValidator {
public:
    static bool isValidPhone(string phone) {
        if (phone.length() != 10) return false;

        for (char c : phone) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
};

#endif