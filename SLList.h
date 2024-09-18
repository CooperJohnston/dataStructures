#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
    }

    void push_back(T item) {
        Node* nodeNuevo = new Node(item);
        if (head == nullptr) {
            tail = nodeNuevo;
            head = nodeNuevo;
        }
        else {
            tail ->next = nodeNuevo;
            tail = nodeNuevo;
        }
        count++;
    }

    void pop_back() {
        return remove(size()-1);
    }

    const T& front() const {
        return head -> value;
    }

    int size() const {
        return count;
    }
    void remove(int position) {
        if (position >= size())
            return;
// case 1: position = 0
        if (position == 0) {
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
// case 2: position = size()-1;
        else if (position == (size() - 1)) {
// find the object before the last one
            Node *itr = head;
            for (int i = 0; i < (position - 1); i++)
                itr = itr->next;
            Node *tmp = tail;
            itr->next = nullptr;
            delete tmp;
            tail = itr;
        }
// case 3: removing something in the middle
        else {
            Node *itr = head;
            for (int i = 0; i < (position - 1); i++)
                itr = itr->next;
            Node *tmp = itr->next;
            itr->next = itr->next->next;
            delete tmp;
        }
        count--;
    }
    void clear(){
        while (head != nullptr)
            remove(0);
    }
private:
    Node* head;
    Node* tail;
    int count;
};
