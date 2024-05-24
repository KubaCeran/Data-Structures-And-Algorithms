#include <iostream>
using namespace std;

class Node {
public:
    Node(int val) {
        value = val;
        next = nullptr;
    }
    int value;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        head = new Node(value);
        tail = head;
        length = 1;
    };

    ~LinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
            length--;
        }
    }

    int getHeadValue() {
        return head->value;
    }

    int getTailValue() {
        return tail->value;
    }

    int getLength() {
        return length;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        if (length == 1) {
            delete tail;
            head = nullptr;
            tail = nullptr;
        } 
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        length--;
    }
};