#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

// ================= CLASS PERSON =================
class Person {
private:
    string name;
    string phone;

public:
    // Constructor
    Person(string name = "", string phone = "")
        : name(name), phone(phone) {
    }

    // Destructor
    virtual ~Person() {}

    // Input
    virtual void input() {
        cout << "Nhap ten: ";
        getline(cin, name);

        cout << "Nhap so dien thoai: ";
        getline(cin, phone);
    }

    // Output
    virtual void output() const {
        cout << "Ten: " << name
            << " | Phone: " << phone;
    }

    // Getter
    string getName() const { return name; }
    string getPhone() const { return phone; }

    // Setter
    void setName(const string& name) { this->name = name; }
    void setPhone(const string& phone) { this->phone = phone; }

    // Operator overloading
    bool operator==(const Person& other) const {
        return this->phone == other.phone;
    }

    bool operator<(const Person& other) const {
        return this->name < other.name;
    }

    // Convert to string (save file)
    virtual string toString() const {
        return "Person," + name + "," + phone;
    }

    // Load from string
    virtual void fromString(const string& data) {
        stringstream ss(data);
        string type;
        getline(ss, type, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
    }

    // Validate phone
    bool isValidPhone() const {
        if (phone.length() < 9 || phone.length() > 11) return false;
        for (char c : phone) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
};

// ================= MAIN =================
int main() {
    vector<Person> list;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them danh ba\n";
        cout << "2. Hien thi\n";
        cout << "3. Tim theo ten\n";
        cout << "4. Xoa theo phone\n";
        cout << "5. Sap xep theo ten\n";
        cout << "6. Luu file\n";
        cout << "7. Doc file\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Person p;
            p.input();

            if (!p.isValidPhone()) {
                cout << "So dien thoai khong hop le!\n";
            }
            else {
                list.push_back(p);
            }
        }

        else if (choice == 2) {
            cout << "\n===== DANH BA =====\n";
            for (auto& p : list) {
                p.output();
                cout << endl;
            }
        }

        else if (choice == 3) {
            string name;
            cout << "Nhap ten can tim: ";
            getline(cin, name);

            for (auto& p : list) {
                if (p.getName() == name) {
                    p.output();
                    cout << endl;
                }
            }
        }

        else if (choice == 4) {
            string phone;
            cout << "Nhap phone can xoa: ";
            getline(cin, phone);

            list.erase(remove_if(list.begin(), list.end(),
                [&](Person& p) {
                    return p.getPhone() == phone;
                }), list.end());

            cout << "Da xoa!\n";
        }

        else if (choice == 5) {
            sort(list.begin(), list.end());
            cout << "Da sap xep!\n";
        }

        else if (choice == 6) {
            ofstream file("contacts.txt");
            for (auto& p : list) {
                file << p.toString() << endl;
            }
            file.close();
            cout << "Da luu file!\n";
        }

        else if (choice == 7) {
            ifstream file("contacts.txt");
            string line;

            list.clear();

            while (getline(file, line)) {
                Person p;
                p.fromString(line);
                list.push_back(p);
            }

            file.close();
            cout << "Da doc file!\n";
        }

    } while (choice != 0);

    return 0;
}
