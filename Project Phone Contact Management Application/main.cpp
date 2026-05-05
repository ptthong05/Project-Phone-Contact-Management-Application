#include <iostream>
#include "ContactManager.h"
#include "FileHandler.h"
#include "PhoneValidator.h"
using namespace std;

int main() {
    ContactManager cm;
    FileHandler fh;

    string filename;
  
    while (true) {
        cout << "Enter file name: ";
        cin >> filename;

        cm = ContactManager(); 

        if (fh.loadFromFile(filename, cm)) {
            cout << "Tai file thanh cong! Vui long chon.\n";
            break;
        } else {
            cout << "Khong tim thay file! Nhap lai.\n";
        }
    }

    int choice;
    do {
        cout << "\n1. Display\n2. Add\n3. Search Name\n4. Search Phone\n";
        cout << "5. Update\n6. Delete\n7. Filter\n8. Sort\n9. Save\n0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) {
            cm.displayContacts();
        }

        else if (choice == 2) {
            string name, phone, rel;
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);

            while (!cm.isValidName(name)) {
                cout << "Name khong hop le! Nhap lai: ";
                getline(cin, name);
            }
            cout << "Phone: ";
            cin >> phone;
            while (!PhoneValidator::isValidPhone(phone)) {
                cout << "Invalid phone! Nhap lai: ";
                cin >> phone;
            }
            if (cm.isDuplicatePhone(phone)) {
                continue;
            }
            int relChoice;

            while (true) {
                cout << "Chon relationship:\n";
                cout << "1. friends\n";
                cout << "2. teacher\n";
                cout << "3. family\n";
                cout << "4. colleague\n";
                cout << "5. Khac\n";
                cout << "Choose (1-5): ";
                cin >> relChoice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Nhap sai dinh dang! Vui long nhap so 1-5.\n";
                    continue;
                }

                if (relChoice < 1 || relChoice > 5) {
                    cout << "Lua chon khong hop le! Nhap lai (1-5).\n";
                    continue;
                }
                break;
            }

            switch (relChoice) {
                case 1: rel = "friends"; break;
                case 2: rel = "teacher"; break;
                case 3: rel = "family"; break;
                case 4: rel = "colleague"; break;

                case 5:
                    cout << "Nhap relationship: ";
                    cin.ignore();
                    getline(cin, rel);
                    break;
            }
            cm.addContact(Contact(name, phone, rel));
            cout << "Da them lien he thanh cong!\n";
        }

        else if (choice == 3) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            if(!cm.searchName(name)) {
                cout<<"Khong co ten trong danh sach!\n";
            }
        }

        else if (choice == 4) {
            string phone;
            cout << "Enter phone: ";
            cin >> phone;
            while (!PhoneValidator::isValidPhone(phone)) {
                cout << "Invalid phone! Nhap lai: ";
                cin >> phone;
            }
            if(!cm.searchPhone(phone)) {
                cout<<"Khong co sdt trong danh sach!\n";
            }
        }

        else if (choice == 5) {
            string phone;
            cout << "Enter phone: ";
            cin >> phone;
            bool updated = cm.updateByPhone(phone);

            if (updated) {
                fh.saveToFile(filename, cm);
                cout << "Da cap nhat va luu file!\n";
            }
        }

        else if (choice == 6) {
            string name;
            cout << "Enter name: ";
            cin >> name;
            cm.deleteByName(name);
        }

        else if (choice == 7) {
            string rel;
            int relChoice;

            cout << "Chon relationship:\n";
            cout << "1. friends\n";
            cout << "2. teacher\n";
            cout << "3. family\n";
            cout << "4. colleague\n";
            cout << "5. Khac\n";
            cout << "Choose: ";
            cin >> relChoice;

            switch (relChoice) {
                case 1: rel = "friends"; break;
                case 2: rel = "teacher"; break;
                case 3: rel = "family"; break;
                case 4: rel = "colleague"; break;
                case 5:
                    cout << "Nhap relationship: ";
                    cin.ignore();
                    getline(cin, rel);
                    break;
                default:
                    cout << "Lua chon khong hop le!\n";
                    continue;
            }       
            cm.filterByRelationship(rel);
        }

        else if (choice == 8) {
            int sortChoice;
            cout << "1. Sort by Name\n";
            cout << "2. Sort by Relationship\n";
            cout << "Choose: ";
            cin >> sortChoice;

            if (sortChoice == 1) {
                cm.sortByName();
            } else if (sortChoice == 2) {
                cm.sortByRelationship();
            } else {
                cout << "Lua chon khong hop le!\n";
            }
        }

        else if (choice == 9) {
            fh.saveToFile(filename, cm);
            cout << "Saved!\n";
        }

    } while (choice != 0);

    return 0;
}