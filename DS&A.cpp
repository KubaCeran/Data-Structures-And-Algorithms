#include <iostream>
#include "LinkedList.cpp"


int main()
{
    LinkedList* list = new LinkedList(15);
    list->append(14);
    list->append(13);
    list->deleteLast();
    list->printList();
}
