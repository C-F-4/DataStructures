#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node* next;
public:
    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    ~Node() {
        delete next;
        this->next = nullptr;
    }

    void setData(int data) {
        this->data = data;
    }

    void setNext(Node* next) {
        this->next = next;
    }

    int getData() {
        return this->data;
    }

    Node* getNext() {
        return this->next;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        this->head = nullptr;
    }

    LinkedList(Node* head) {
        this->head = head;
    }

    ~LinkedList() {
        delete head;
        this->head = nullptr;
    }

    void insertBeg(int data) {
        Node* new_node = new Node(data, this->head);
        this->head = new_node;
    }

    void insertAfter(int data, Node* key_node) {
        if(key_node == nullptr) {
            cerr << "Err: Key Node can't be null" << endl;
        }
        else {
            Node* tmp = this->head;
            Node* new_node = new Node(data);
            if(tmp == key_node) {
                new_node->setNext(tmp);
                this->head = new_node;
            }
            else {
                while(tmp != key_node && tmp != nullptr) {
                    tmp = tmp->getNext();
                }
                if(tmp == nullptr) {
                    cerr << "Err: Key Node not found" << endl;
                }
                else {
                    new_node->setNext(tmp->getNext());
                    tmp->setNext(new_node);
                }
            }
        }
    }

    void insertBefore(int data, Node* key_node) {
        if(key_node == nullptr) {
            cerr << "Err: Key Node can't be null" << endl;
        }
        else {
            Node* tmp = this->head;
            Node* new_node = new Node(data, key_node);
            if(tmp == key_node) {
                this->head = new_node;
            }
            else {
                while(tmp->getNext() != key_node && tmp != nullptr) {
                    tmp = tmp->getNext();
                }
                if(tmp == nullptr) {
                    cerr << "Err: Key Node not found" << endl;
                }
                else {
                    tmp->setNext(new_node);
                }
            }
        }
    }

    void insertEnd(int data) {
        Node* new_node = new Node(data);
        Node* tmp = this->head;
        while(tmp->getNext() != nullptr) {
            tmp = tmp->getNext();
        }
        tmp->setNext(new_node);
    }

    void printList() {
        Node* tmp = this->head;
        cout << ">> ";
        while(tmp != nullptr) {
            cout << tmp->getData() << ' ';
            tmp = tmp->getNext();
        }
        cout << endl;
    }

    Node* getHead() {
        return this->head;
    }

    /* Code Bloat */
    inline Node* getFirst(){
        return this->getHead();
    }

    Node* getLast() {
        Node* tmp = this->head;
        while(tmp->getNext() != nullptr) {
            tmp = tmp->getNext();
        }
        return tmp;
    }
};

int main()
{
    LinkedList* llist = new LinkedList();
    llist->insertBeg(1);
    llist->insertEnd(2);
    llist->insertEnd(3);
    llist->insertEnd(4);
    llist->insertAfter(5, llist->getLast());
    if(llist->getHead() != nullptr)
        llist->insertBefore(0, llist->getHead());
    llist->printList();
    return 0;
}
