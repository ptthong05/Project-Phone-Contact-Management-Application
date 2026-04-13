#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    string phone;

public:
    // Constructor
    Person(string n = "", string p = "") {
        name = n;
        phone = p;
    }

    // Getter
    string getName() const { return name; }
    string getPhone() const { return phone; }

    // Setter
    void setName(string n) { name = n; }
    void setPhone(string p) { phone = p; }

    virtual void display() const {
        cout << "Name: " << name << ", Phone: " << phone;
    }

    bool operator>(const Person& other) const {
        return name > other.name;
    }

    friend istream& operator>>(istream& in, Person& p) {
        cout << "Enter name: ";
        getline(in >> ws, p.name);
        cout << "Enter phone: ";
        getline(in, p.phone);
        return in;
    }

   
    friend ostream& operator<<(ostream& out, const Person& p) {
        out << "Name: " << p.name << ", Phone: " << p.phone;
        return out;
    }
};