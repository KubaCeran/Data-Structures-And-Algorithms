#include <iostream>
#include "LinkedList.cpp"


int main()
{
    LinkedList* list = new LinkedList();
    list->append(0);
    list->append(1);
    list->append(2);
    list->append(3);
    list->printList();
    cout << endl;
    list->reverse();
    list->printList();
    /*cout << endl;

    cout << list->getHeadValue() << endl;
    cout << list->getTailValue() << endl;
    cout << list->getLength() << endl;*/

    delete list;
}
