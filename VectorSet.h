#pragma once
#include <algorithm>
#include <vector>

template<class T>
class VectorSet {
private:
std::vector<T>items_in;
public:
    bool contains(T item) const {
        if (std::find(items_in.begin(), items_in.end(), item) != items_in.end()) {
            return true;
        }
        // implement contains here
        return false;
        // return true if item is in the set and false if not
    }

    bool insert(T item) {
        // implement insert here
        if (contains(item) == true) {
            return false;
        }
        else
        {items_in.insert(items_in.end(),item);
            return true;}

        // return true if item is inserted and false if item is already in the
        // set
    }

    bool remove(T item) {
        // implement remove here
        if (contains(item) == true){
            items_in.erase((std::find(items_in.begin(), items_in.end(),item)));
            return true;

        }
        return false;

        // return true if item is removed and false if item wasn't in the set
    }

    int size() const {
        // implement size here
        int leng = 0;
        for (const T& element : items_in) {
            leng ++;
        }
        return leng;



        // return the number of items in the set
    }

    bool empty() const {
        // implement empty here
        return items_in.empty();
        // return true if the set is empty and return false otherwise
    }

    void clear() {
        // implement clear here
        items_in.clear();
        // remove all items from the set
    }

};
