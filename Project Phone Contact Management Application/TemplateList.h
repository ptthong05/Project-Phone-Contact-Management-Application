#ifndef TEMPLATELIST_H
#define TEMPLATELIST_H

#include <vector>
using namespace std;

template <class T>
class TemplateList {
private:
    vector<T> items;

public:
    void add(T item) {
        items.push_back(item);
    }

    void remove(int index) {
        if (index >= 0 && index < items.size())
            items.erase(items.begin() + index);
    }


    T& get(int index) {
        return items[index];
    }


    const T& get(int index) const {
        return items[index];
    }

    int size() const {
        return items.size();
    }

    vector<T>& getAll() {
        return items;
    }
};

#endif