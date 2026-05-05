#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string phoneNumber;

public:
    
    // Constructor có tham số
    Person(string _name, string _phoneNumber)
        : name(_name), phoneNumber(_phoneNumber) {}

    // Getter
    string getName() const { return name; }

    string getPhoneNumber() const { return phoneNumber; }

    // Setter 
    void setName(string name) { this->name = name; }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    // Hàm display 
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Phone: " << phoneNumber << endl;
    }

    // Destructor
    virtual ~Person() {}
};

#endif