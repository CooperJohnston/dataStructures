#pragma once

#include <functional>
#include <list>
#include <iostream>
#include <unordered_map>


using namespace std;

template<class T>
class HashSet {
public:
    HashSet() {

        n = 0;
    }

    ~HashSet() {clear();}

    bool insert(T item) {
        //cout << "I am created, and I am trying to insert a value." << endl;
        if (contains(item)) {
            return false;
        }

        // return true if item was inserted, false if item was already in the set
        //cout << " I made it far enough to insert somehting. TeE HEE. " << endl;
        size_t hashcode = std::hash<T>()(item);
        array[hashcode].push_back(item);
        n++;
        return true;

    }

    bool remove(T item) {
        // implement remove here
        // return true if item was removed, false if item wasn't in the set
        if (contains(item) == false) {
            return false;
        }
        else {
            size_t hashcode = std::hash<T>()(item);
            array[hashcode].remove(item);
            n--;
            return true;
        }



    }

    bool contains(T item) const {
        size_t hashcode = std::hash<T>()(item);
        if (array.count(hashcode) == 0) {
            return false;
        }
        else {
            list<T> info = array.at(hashcode);
            if (find(info.begin(),info.end(), item) != info.end()){
                return true;
            }
            return false;
        }



    }

    void clear() {
        array.clear();
        n --;
    }

    int size() const {
        return n;

    }
private:

    unordered_map<size_t, list<T> > array;
    int n;
};
