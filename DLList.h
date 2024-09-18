#pragma once

#include <iostream>
#include <string>
using namespace std;

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    DLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~DLList() {clear();}

    const Node* get_head() const {
        return head;
    }

    void push_front(T item) {
        // implement push_front here
        Node* nodeNuevo = new Node(item);
        if (head == nullptr){
            //cout << " My Head is born" << endl;
            tail = nodeNuevo;
            //cout << " My Head is born" << endl;
            head = nodeNuevo;
            //cout << " My Head is born" << endl;
        }
        else {//cout << " I DID IT" << endl;
            head -> prev = nodeNuevo;
            //
            nodeNuevo -> next = head;
            head = nodeNuevo;
        }
        count ++;
        //cout << " We even went up the right way!" << endl;
    }
    void push_back(T item) {
        Node* nodeNuevo = new Node(item);
        if (head == nullptr){
            tail = nodeNuevo;
            head = nodeNuevo;

        }
        else {
            tail ->next = nodeNuevo;
            nodeNuevo ->prev = tail;
            tail = nodeNuevo;
        }
        count ++;
    }
    void insert(T item, int position) {
        if (position < 0 || position > size()){
            throw std::out_of_range("Index is out of range.");

        }
        if (position == 0){
            push_front(item);
            //cout << " I put it in, aahah" << endl;
            //count ++;
        }
        else if(position == size()){
            push_back(item);
            //count ++;
        }
        else {
            Node *nodeNuevo = new Node(item);
            Node *itr = head;
            for (int i = 0; i < (position - 1); i++)
                itr = itr->next;
            Node *tmp = itr->next;
            tmp->prev = nodeNuevo;
            itr->next = nodeNuevo;
            nodeNuevo->prev = itr;
            nodeNuevo->next = tmp;
            count++;
        }
    }

    void pop_front() {
        if (size() == 0){
            throw std::length_error("The list is empty. There is no front.");
        }
        Node* temp = head;

        head = temp->next;

        //head ->prev = nullptr;
        delete temp;
        //cout << head -> prev << endl;
        count --;
        //delete temp;
        //cout<< "removed it." << endl;
    }
    void pop_back() {
        if (size() == 0){
            throw std::length_error("The list is empty. There is no back.");
        }
        Node* temp = tail;
        tail = temp->prev;
        tail ->next = nullptr;
        count --;
        delete temp;
    }
    void remove(int position) {
        if (position < 0 || position >= size()){
            throw std::out_of_range("Index is out of range.");

        }
        if (position == 0){
            //cout << " I am removing the front now. " << endl;
            pop_front();
            //cout << " I am removing the front now. " << endl;
        }
        else if (position == count -1) {
            pop_back();
        }
        else {
            Node* itr = head;
            for (int i = 0; i < (position-1); i++)
                itr = itr->next;
            Node* tmp = itr->next;

            itr->next = itr->next->next;
            itr ->next-> prev = itr;
            delete tmp;
            count --;
        }

    }

    const T& front() const {
        if (size() == 0){
            throw std::length_error("The list is empty. There is no front.");
        }
        return head ->value;
    }
    const T& back() const {
        if (size() == 0){
            throw std::length_error("The list is empty. There is no back.");
        }
        return tail ->value;
    }
    const T& at(int index) const {
        if (index < 0 || index >= size()){
            throw std::out_of_range("Index is out of range.");

        }

            Node* itr = head;
            for (int i = 0; i < (index); i++)
                itr = itr->next;
            return itr ->value;



    }

    bool contains(const T& item) const {
        Node* itr = head;
        while (itr != nullptr) {
            if (itr->value == item){
                return true;
            }
            itr = itr->next;

        }
        return false;

    }

    int size() const {
        return count;
    }

    void clear() {
        while (head != nullptr) {
            remove(0);
        }
    }
private:
    Node* head;
    Node* tail;
    int count;
};
