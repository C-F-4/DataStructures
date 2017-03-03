#include <iostream>
//#include "Node.h"
#include "List.hpp"

using namespace std;

int main() {
    LinkedList* llist = new LinkedList();
    llist->insertBeg(1);
    llist->insertEnd(2);
    llist->insertEnd(3);
    llist->insertEnd(4);
    llist->insertAfter(5, llist->getLast());
    if(llist->getHead() != nullptr)
        llist->insertBefore(0, llist->getHead());
    llist->printList();
    llist->deleteBeg();
    llist->deleteEnd();
    llist->printList();
    llist->deleteNode(llist->getHead());
    llist->printList();
    llist->deleteNode(llist->getLast());
    llist->printList();
    unsigned int i = 0;
    cout << ">> ";
    while(llist->isNotEmpty()) {
        cout << llist->getFirst()->getData() << ' ';
        llist->deleteBeg();
    }
    cout << endl;

    llist->insertBeg(1);
    llist->insertBeg(1);
    llist->insertEnd(2);
    llist->insertEnd(3);
    llist->insertEnd(1);
    llist->insertEnd(1);
    i = 0;
    size_t size_l = llist->getSize();
    cout << ">> ";
    while(i != size_l) {
        cout << llist->getElement(i++) << ' ';
    }
    cout << endl;
    cout << "Deleted Nodes Counter: " << llist->deleteAll(1) << endl;
    llist->printList();
    cout << "Size: " << llist->getSize() << ' '
        << llist->getSizeR(llist->getHead()) << endl;
    cout << ">> ";
    llist->printListR(llist->getHead());
    cout << (llist->contains(1)?("true"):("false")) << endl;
    cout << (llist->containsR(llist->getHead(), 2)?("true"):("false")) << endl;
    cout << (llist->containsR(llist->getHead(), 1)?("true"):("false")) << endl;
    llist->insertionSort();
    llist->insertEnd(INT_MAX);
    llist->printList();
    LinkedList llist_2(*llist);
    llist_2.printList();
    return 0;
}
