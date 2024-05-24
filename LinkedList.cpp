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

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node* getAtIndex(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* result = head;
        for (int i = 0; i < index; i++) {
            result = result->next;
        }
        return result;
    }

    bool setAtIndex(int index, int value) {
        Node* temp = getAtIndex(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) { 
            prepend(value); 
            return true; 
        };
        if (index == length) {
            append(value);
            return true;
        }
        Node* temp = new Node(value);
        Node* node = getAtIndex(index-1);
        temp->next = node->next;
        node->next = temp;
        length++;
        return true;
    }

    void deleteNodeAtIndex(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1)  return deleteLast();
        Node* prev = getAtIndex(index-1);
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }
};