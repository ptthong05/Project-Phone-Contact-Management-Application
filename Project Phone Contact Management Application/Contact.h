#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Contact : public Person {
private:
    string relationship;

public:

    Contact(string _name, string _phone, string _relationship)
        : Person(_name, _phone), relationship(_relationship) {}

    string getRelationship() const { return relationship; }

    void setRelationship(string relationship) {
        this->relationship = relationship;
    }

    // override
    void display() override {
        cout << name << " - " << phoneNumber
             << " - " << relationship << endl;
    }

    // operator overloading
    bool operator==(const Contact& c) {
        return phoneNumber == c.phoneNumber;
    }

    friend ostream& operator<<(ostream& out, const Contact& c) {
        out << c.name << " "
            << c.phoneNumber << " "
            << c.relationship;
        return out;
    }
};

#endif