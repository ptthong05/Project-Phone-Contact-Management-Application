#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include "ContactManager.h"
using namespace std;

class FileHandler {
public:
    bool loadFromFile(string filename, ContactManager& cm) {
        ifstream file(filename);

        if (!file.is_open()) {
            return false;
        }

        string name, phone, rel;
        while (file >> name >> phone >> rel) {
            cm.addContact(Contact(name, phone, rel));
        }

        file.close();
        return true;
    }

    
    void saveToFile(string filename, ContactManager& cm) {
        ofstream file(filename);

        for (int i = 0; i < cm.size(); i++) {
            file << cm.get(i) << endl;
        }

        file.close();
    }
};

#endif