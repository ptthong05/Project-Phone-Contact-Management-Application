#pragma once
#include "Person.h"

class Contact : public Person {
private:
    string email;

public:
    Contact(string n="", string p="", string e="") 
        : Person(n,p) {
        email = e;
    }

    void display() const override {
        Person::display();
        cout << ", Email: " << email;
    }

    friend istream& operator>>(istream& in, Contact& c) {
        in >> (Person&)c;

        cout << "Enter email: ";
        getline(in >> ws, c.email);

        return in;
    }

    friend ostream& operator<<(ostream& out, const Contact& c) {
        out << (Person&)c
            << ", Email: " << c.email;
        return out;
    }
};
