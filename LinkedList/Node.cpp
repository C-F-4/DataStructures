#include "Node.h"

/*
** Constructors && Destructors
*/
Node::Node ():data(0), next(nullptr) {}

Node::Node (int data):data(data), next(nullptr) {}

Node::Node (int data, Node* next):data(data), next(next) {}

Node::Node (const Node& node):data(node.data), next(node.next) {
}

Node::~Node () {
    delete next;
    this->next = nullptr;
}

/*
** Setter Methods
*/
void Node::setData (int data) {
    this->data = data;
}

void Node::setNext (Node* next) {
    this->next = next;
}

/*
** Getter Methods
*/
int Node::getData () {
    return this->data;
}

Node* Node::getNext () {
    return this->next;
}
