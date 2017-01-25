// List.cpp

#include "List.h"

/*
** Constructors && Destructors
*/
LinkedList::LinkedList ():head(nullptr) {}

LinkedList::LinkedList (Node* head):head(head) {}

LinkedList::LinkedList (const LinkedList& xlist):head(nullptr) {
    Node* node = xlist.head;
    while(node != nullptr) {
        this->append(new Node(node->getData()));
        node = node->getNext();
    }
}

LinkedList::~ LinkedList () {
    delete head;
    this->head = nullptr;
}

/*
** Insertion Methods
*/
void LinkedList::insertBeg (int data) {
    Node* new_node = new Node(data, this->head);
    this->head = new_node;
}

void LinkedList::insertAfter (int data, Node* key_node) {
    if(key_node == nullptr) {
        cerr << "Err: Key Node can't be null" << endl;
    } else {
        Node* tmp = this->head;
        Node* new_node = new Node(data);
        if(tmp == key_node) {
            new_node->setNext(tmp);
            this->head = new_node;
        } else {
            while(tmp != key_node && tmp != nullptr) {
                tmp = tmp->getNext();
            }
            if(tmp == nullptr) {
                cerr << "Err: Key Node not found" << endl;
            } else {
                new_node->setNext(tmp->getNext());
                tmp->setNext(new_node);
            }
        }
    }
}

void LinkedList::insertBefore (int data, Node* key_node) {
    if(key_node == nullptr) {
        if(this->head != nullptr)
            cerr << "Err: Key Node can't be null" << endl;
        else if(this->head == nullptr) {
            Node* new_node = new Node(data, key_node);
            this->head = new_node;
        }
    } else {
        Node* tmp = this->head;
        Node* new_node = new Node(data, key_node);
        if(tmp == key_node) {
            this->head = new_node;
        } else {
            while(tmp->getNext() != key_node && tmp != nullptr) {
                tmp = tmp->getNext();
            }
            if(tmp == nullptr) {
                cerr << "Err: Key Node not found" << endl;
            } else {
                tmp->setNext(new_node);
            }
        }
    }
}
void LinkedList::insertEnd (int data) {
    Node* new_node = new Node(data);
    Node* tmp = this->head;
    while(tmp->getNext() != nullptr) {
        tmp = tmp->getNext();
    }
    tmp->setNext(new_node);
}

void LinkedList::append (Node* node) {
    Node* tmp = this->head;
    if(tmp == nullptr) {
        this->head = node;
    } else {
        while(tmp!= nullptr) {
            if(tmp->getNext() == nullptr) {
                tmp->setNext(node);
                break;
            }
            tmp = tmp->getNext();
        }
    }
}

/*
** Deletion Methods
*/
void LinkedList::deleteBeg () {
    if(this->head == nullptr) {
        cerr << "Err: List doesn't have any elements to delete" << endl;
    } else {
        Node* tmp = this->head;
        this->head = this->head->getNext();
        tmp->setNext(nullptr);
        delete tmp;
    }
}

void LinkedList::deleteNode (Node* key_node) {
    if(key_node == nullptr) {
        cerr << "Err: Key Node can't be null" << endl;
    } else {
        Node* tmp = this->head;
        if(key_node == tmp) {
            this->head = this->head->getNext();
            tmp->setNext(nullptr);
            delete tmp;
        } else {
            while(tmp->getNext() != key_node && tmp != nullptr) {
                tmp = tmp->getNext();
            }
            if(tmp == nullptr) {
                cerr << "Err: Key Node not found" << endl;
            } else {
                Node* tmp2 = tmp->getNext();
                tmp->setNext(tmp->getNext()->getNext());
                tmp2->setNext(nullptr);
                delete tmp2;
            }
        }
    }
}

void LinkedList::deleteEnd () {
    if(this->head == nullptr) {
        cerr << "Err: List doesn't have any elements to delete" << endl;
    } else if(this->head->getNext() == nullptr) {
        delete this->head;
        this->head = nullptr;
    } else {
        Node* tmp = this->head;
        Node* del_node = nullptr;
        while(tmp->getNext() != nullptr && tmp->getNext()->getNext() != nullptr) {
            tmp = tmp->getNext();
        }
        del_node = tmp->getNext();
        tmp->setNext(nullptr);
        delete del_node;
    }
}

int LinkedList::deleteAll (int key) {
    Node* del_node = nullptr;
    Node* tmp = this->head;
    int ct = 0;
    while(tmp->getData() == key) {
        this->head = this->head->getNext();
        tmp->setNext(nullptr);
        delete tmp;
        tmp = this->head;
        ct++;
    }
    while(tmp != nullptr && tmp->getNext() != nullptr) {
        if(tmp->getNext()->getData() == key) {
            del_node = tmp->getNext();
            tmp->setNext(tmp->getNext()->getNext());
            del_node->setNext(nullptr);
            delete del_node;
            ct++;
        } else {
            tmp = tmp->getNext();
        }
    }
    return ct;
}

/*
** Print Methods
*/
void LinkedList::printListR (Node* tmp) {
    if(tmp == nullptr) {
        cout << endl;
        return;
    }
    cout << tmp->getData() << ' ';
    this->printListR(tmp->getNext());
}

void LinkedList::printList () {
    Node* tmp = this->head;
    cout << ">> ";
    while(tmp != nullptr) {
        cout << tmp->getData() << ' ';
        tmp = tmp->getNext();
    }
    cout << endl;
}

/*
** Get Property Methods
*/
size_t LinkedList::getSizeR (Node* tmp) {
    if(tmp == nullptr) {
        return 0;
    }
    return (1 + this->getSizeR(tmp->getNext()));
}

size_t LinkedList::getSize () {
    Node* tmp = this->head;
    size_t size_l = 0;
    while(tmp != nullptr) {
        tmp = tmp->getNext();
        size_l++;
    }
    return size_l;
}

Node* LinkedList::getHead () {
    return this->head;
}

Node* LinkedList::getLast () {
    Node* tmp = this->head;
    while(tmp->getNext() != nullptr) {
        tmp = tmp->getNext();
    }
    return tmp;
}

bool LinkedList::isEmpty () {
    return ((this->head == nullptr)?(true):(false));
}

bool LinkedList::isNotEmpty () {
    return ((this->head != nullptr)?(true):(false));
}

/*
** Search Methods
*/
int LinkedList::getElement (int pos) {
    if(this->head == nullptr) {
        cerr << "Err: Element Not found" << endl;
        return INT_MIN;
    } else {
        Node* tmp = this->head;
        int i = 0;
        while(tmp != nullptr && i != pos) {
            tmp = tmp->getNext();
            i++;
        }
        if(i == pos)
            return tmp->getData();
        else {
            cerr << "Err: Element Not found" << endl;
            return INT_MIN;
        }
    }
}

bool LinkedList::contains (int key) {
    Node* tmp = this->head;
    while(tmp != nullptr) {
        if(tmp->getData() == key)
            return true;
        tmp = tmp->getNext();
    }
    return false;
}

bool LinkedList::containsR (Node* tmp, int key) {
    if(tmp == nullptr) {
        return false;
    } else if(tmp->getData() == key) {
        return true;
    }
    return this->containsR(tmp->getNext(), key);
}

/*
** Sorting Methods
*/
void LinkedList::insertSorted (Node** sorted, int key) {
    Node* new_node = new Node(key);
    if((*sorted) == nullptr) {
        new_node->setNext(nullptr);
        *sorted = new_node;
    } else if ((*sorted)->getData() >= new_node->getData()) {
        new_node->setNext(*sorted);
        *sorted = new_node;
    } else {
        Node* cur = *sorted;
        // Locate node before the point of insertion
        while(cur->getNext() != nullptr) {
            if(cur->getNext()->getData() < new_node->getData()) {
                break;
            }
            cur = cur->getNext();
        }
        new_node->setNext(cur->getNext());
        cur->setNext(new_node);
    }
}

void LinkedList::insertionSort () {
    Node* cur = this->head;
    Node* next = nullptr;
    Node* sorted = nullptr;
    while(cur != nullptr) {
        next = cur->getNext();
        this->insertSorted(&sorted, cur->getData());
        cur->setNext(nullptr);
        delete cur;
        cur = next;
    }
    this->head = sorted;
}
