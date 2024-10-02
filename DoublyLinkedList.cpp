#include <iostream>
#include "Node.cpp"
using namespace std;

//Remove last element -> O(1)
//Add to the end -> O(1)
//Remove first element -> O(1)
//Add to the begining -> O(1)
//Insert between -> O(n)
//Remove between -> O(n)
//Search for the value -> O(n)
class DoublyLinkedList {
private:
	DoublyNode* head;
	DoublyNode* tail;
	int length;
public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {};

    void printList() {
        DoublyNode* temp = head;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
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

    void append(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
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
            DoublyNode* temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        length--;
    }

    void prepend(int value) {
        DoublyNode* newNode = new DoublyNode(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            DoublyNode* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        length--;
    }

    DoublyNode* getAtIndex(int index) {
        if (index < 0 || index >= length) return nullptr;
        DoublyNode* result = nullptr;
        if(index < length/2) {
            result = head;
            for (int i = 0; i < index; i++) {
                result = result->next;
            }
        }
        else {
            result = tail;
            for (int i = length - 1; i > index; i--) {
                result = result->prev;
            }
        }
        return result;
    }

    bool trySetAtIndex(int index, int value) {
        DoublyNode* temp = getAtIndex(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool tryInsert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        DoublyNode* newNode = new DoublyNode(value);
        DoublyNode* oldNode = getAtIndex(index);
        newNode->next = oldNode;
        newNode->prev = oldNode->prev;
        oldNode->prev->next = newNode;
        oldNode->prev = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        DoublyNode* nodeToDelete = getAtIndex(index);
        nodeToDelete->next->prev = nodeToDelete->prev;
        nodeToDelete->prev->next = nodeToDelete->next;
        delete nodeToDelete;
        length--;
    }
};
