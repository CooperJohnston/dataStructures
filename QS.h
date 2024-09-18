#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T>
int medianOfThree(std::vector<T>& array, int left, int right) {
    int middle = (left + right) / 2;
    //cout<< middle << " is between " << left << " and " << right <<endl;
    if (array[left] > array[middle]) {
        swap(array[left],array[middle]);
    }
    if (array[left] > array[right]) {
        swap(array[left],array[right]);}

    if (array[middle] > array[right]){
        swap(array[middle],array[right]);

    }
    //cout << array[left] << array[middle] << array[right] << endl;
    return middle;
}

template<class T>
int partition(std::vector<T>& array, int left, int right) {
    // implement partition here

    int middle = medianOfThree(array, left, right);

    T pivot_val = array[middle];
    //cout << middle << " is my middle" << " and my val is "<< pivot_val << endl;
    swap(array[left], array[middle]);

    //cout << middle << " is my middle" << " and my val is "<< pivot_val << endl;
    int up = left + 1;
    int down = right;
    while (up < down){
        while (array[up] <= pivot_val || up < right){
            if (up >= right){break;}
            if (array[up] > pivot_val){break;}
            up++;
        }
        while (array[down] > pivot_val || down > left){
            if (down <= left) {
                break;
            }
            if (array[down] <= pivot_val){break;}
            down--;
        }
        if (up < down){
            swap(array[up], array[down]);
        }




    }
    swap(array[left], array[down]);

    return down;
}


template<class T>
void helper(std::vector<T>& array, int left, int right){
    if (right - left > 3) {
        //cout << "I began with " << left << " and " << "right " << right << endl;
        int mid = partition(array, left, right);
        //cout << "mid is " << mid << endl;
        helper(array, left, mid -1);
        helper(array, mid + 1, right);

    }
    else {
        medianOfThree(array, left, right);

    }
}
template<class T>
void sort(std::vector<T>& array) {
    // implement sort here
    // hint: you'll probably want to make a recursive sort_helper function
    int l = 0;
    int r = array.size() -1;
    //cout <<
    helper(array,l,r);

}


