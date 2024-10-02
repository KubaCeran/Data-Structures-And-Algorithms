#include <iostream>
#include "Node.cpp"
using namespace std;

//Remove last element -> O(n)
//Add to the end -> O(1)
//Remove first element -> O(1)
//Add to the begining -> O(1)
//Insert between -> O(n)
//Remove between -> O(n)
//Search for the value -> O(n)
class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList() : head(nullptr), tail(head), length(0) {};

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
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
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

    bool trySetAtIndex(int index, int value) {
        Node* temp = getAtIndex(index);
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
        Node* newNode = new Node(value);
        Node* prev = getAtIndex(index - 1);
        newNode->next = prev->next;
        prev->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* prev = getAtIndex(index - 1);
        Node* nodeToDelete = prev->next;
        prev->next = nodeToDelete->next;
        delete nodeToDelete;
        length--;
    }

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;

        Node* prev = nullptr;
        Node* next = temp->next;
        for (int i = 0; i < length; i++) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
    }

    Node* findMiddleNode() {
        if (head == nullptr) return nullptr;
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    bool hasLoop() {
        if (length == 0) return false;

        Node* slow = head;
        Node* fast = head;


        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }

    Node* findKthFromEnd(int k) {
        Node* fast = head;
        Node* slow = head;

        for (int i = 0; i < k; i++) {
            if (fast == nullptr) return nullptr;
            fast = fast->next;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};