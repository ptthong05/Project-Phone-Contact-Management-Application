#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include "TemplateList.h"
#include "Contact.h"
#include <iostream>
#include <algorithm>
using namespace std;

class ContactManager {
private:
    TemplateList<Contact> contacts;

public:
    void displayContacts() {
        for (int i = 0; i < contacts.size(); i++) {
            contacts.get(i).display();
        }
    }

    bool isValidName(string name) {
        if (name.empty()) return false;

        for (char c : name) {
            if (!isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }

    void addContact(Contact c) {
        contacts.add(c);
    }

    bool isDuplicatePhone(string phone) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getPhoneNumber() == phone) {
                cout << "Thong tin lien he da ton tai:\n";
            contacts.get(i).display(); 
            return true;
            }
        }
    return false;
    }
    

    string toLowerCase(string s) {
        for (int i = 0; i < s.length(); i++) {
            s[i] = tolower(s[i]);
        }
    return s;
    }

    bool searchName(string name) {
        bool found = false;
        string searchNameLower = toLowerCase(name);
        for (int i = 0; i < contacts.size(); i++) {
            string contactNameLower = toLowerCase(contacts.get(i).getName());
            if (contactNameLower == searchNameLower) {
                contacts.get(i).display();
                found = true;
            }
        }
    return found;
    }
    

    bool searchPhone(string phone) {
        bool found = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getPhoneNumber() == phone) {
                contacts.get(i).display();
                found = true;
            }
        }
        return found;
    }
   
    
    bool updateByPhone(string phone) {
        for (int i = 0; i < contacts.size(); i++) {

            if (contacts.get(i).getPhoneNumber() == phone) {

                cout << "Thong tin hien tai:\n";
                contacts.get(i).display();
            
                string newName, newRel;
                int relChoice;

                cout << "New name: ";
                cin.ignore();
                getline(cin, newName);
                while(!isValidName(newName)) {
                    cout<<"Name k hop le!Nhap lai: ";
                    getline(cin, newName);
                }
                
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
                    case 1: newRel = "friends"; break;
                    case 2: newRel = "teacher"; break;
                    case 3: newRel = "family"; break;
                    case 4: newRel = "colleague"; break;
                    case 5:
                        cout << "Nhap relationship: ";
                        cin.ignore();
                        getline(cin, newRel);
                        break;
                }

                contacts.get(i).setName(newName);
                contacts.get(i).setRelationship(newRel);

                cout << "Cap nhat thanh cong!\n";
                return true;
            }
        }
        cout << "Khong tim thay contact!\n";
        return false;
    }   

    
    void deleteByName(string name) {
        vector<int> indexList;
        string searchName = toLowerCase(name); 

        for (int i = 0; i < contacts.size(); i++) {
            string contactName = toLowerCase(contacts.get(i).getName());
            if (contactName == searchName) {
                cout << indexList.size() + 1 << ". ";  
                contacts.get(i).display();

                indexList.push_back(i);
            }
        }

        if (indexList.empty()) {
            cout << "Khong tim thay ten trong danh sach!\n";
            return;
        }

        int choice;
            cout << "Ban muon xoa contact nao? ";
            cin >> choice;

            if (choice < 1 || choice > indexList.size()) {
                cout << "Lua chon khong hop le!\n";
                return;
            }

        int confirm;
        cout << "Ban co chac chan muon xoa?\n";
        cout << "1. Yes\n2. No\n";
        cout << "Choose: ";
        cin >> confirm;

        if (confirm == 1) {
            contacts.remove(indexList[choice - 1]);
            cout << "Da xoa thanh cong!\n";
        } else {
            cout << "Da huy xoa!\n";
        }
    }   


    void filterByRelationship(string rel) {
        bool found;

        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getRelationship() == rel) {
                contacts.get(i).display();
                found = true;
            }
        }

        if (found == false) {
            cout << "Khong co lien he nao!\n";
        }
    }


    void sortByName() {
        sort(contacts.getAll().begin(), contacts.getAll().end(),
            [](Contact a, Contact b) {
                return a.getName() < b.getName();
            });
        cout << "Da sap xep theo ten!\n";
        displayContacts();
    }   

    
    void sortByRelationship() {
        sort(contacts.getAll().begin(), contacts.getAll().end(),
            [](Contact a, Contact b) {
                return a.getRelationship() < b.getRelationship();
            });
        cout << "Da sap xep theo relationship!\n";
        displayContacts();
    }



    
    int size() {
        return contacts.size();              //contacts.size() -- SO LUONG CONTACT CO O FILE    
    }

    Contact& get(int i) {
        return contacts.get(i);             //Lay contact thu i
    }
};

#endif