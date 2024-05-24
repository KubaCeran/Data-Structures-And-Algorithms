#include <iostream>
#include "LinkedList.cpp"


int main()
{
    LinkedList* list = new LinkedList(15);
    list->prepend(14);
    list->prepend(13);
    list->printList();
    list->deleteNodeAtIndex(3);
    cout << endl;
    list->printList();
    cout << "get: " << list->getAtIndex(1)->value;
    delete list;
}
