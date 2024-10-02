class Node {
public:
    Node(int val) {
        value = val;
        next = nullptr;
    };
    int value;
    Node* next;
};

class DoublyNode {
public:
    DoublyNode(int val) {
        value = val;
        next = nullptr;
        prev = nullptr;
    };
    int value;
    DoublyNode* next;
    DoublyNode* prev;
};