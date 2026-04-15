#pragma once
#include <iostream>
using namespace std;

template <class T>
class TemplateList : public T {
private:
    T list[100];
    int n;

public:
    TemplateList() {
        n = 0;
    }

    void add(T x) {
        if (n < 100) {
            list[n++] = x;
        }
    }

    void input() {
        int m;
        cout << "Enter number of contacts: ";
        cin >> m;
        cin.ignore();

        for (int i = 0; i < m; i++) {
            cout << "\nContact " << i + 1 << endl;
            cin >> list[n++];
        }
    }

    void display() {
        cout << "\nContact List:\n";
        for (int i = 0; i < n; i++) {
            cout << list[i] << endl;
        }
    }
};
