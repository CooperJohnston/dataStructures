#pragma once

#include <iostream>
#include <string>

using namespace std;

template<class T>
class Vector {
public:
    Vector() { array = new T[0];
    count = 0;}

    ~Vector() {clear();}

    void push_back(T item) {
        T* new_ar = new T[count+1];
        for (int i = 0; i < count; i++) {
            new_ar[i] = array[i];
        }
        new_ar[count] = item;
        count ++;
        T* temp = array;
        array = new_ar;
        delete[] temp;
    }

    void insert(T item, int position) {
        if (position < 0 || position > count){
            throw out_of_range("Not in range my brother.");
        }
        T* new_ar = new T[count+1];
        for (int i = 0; i < position; i++) {
            new_ar[i] = array[i];
        }
        new_ar[position] = item;
        for (int k = position +1; k <count +1; k++){
            new_ar[k] = array[k-1];
        }
        count ++;
        T* temp = array;
        array = new_ar;
        delete[] temp;
        // implement insert here
    }

    void remove(int position) {
        if (position < 0 || position > count-1){
            throw out_of_range("Not in range my brother.");
        }
        T* new_ar = new T[count-1];
        for (int i = 0; i < position; i++) {
            new_ar[i] = array[i];
        }
        //new_ar[position] = item;
        for (int k = position; k <count-1; k++){
            new_ar[k] = array[k+1];
        }
        count --;
        T* temp = array;
        array = new_ar;
        delete[] temp;
    }

    T& operator[](int index) {
        if (index < 0 || index > count-1){
            throw out_of_range("Not in range my brother.");
        }
        // implement operator[] here
        int i = 0;
        while (i < index) { i++;}
        return array[i];
    }

    int size() const {
        return count;
    }

    void clear() {
        while (count > 0){
            remove(0);
        }
    }
private:
    int count;
    T* array;
};
