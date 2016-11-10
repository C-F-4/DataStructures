#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Node {
private:
  int data;
  Node* next;
public:
  Node() {
    data = 0;
    next = NULL;
  }
  Node(int d) {
    data = d;
    next = NULL;
  }
  Node(int d, Node* n) {
    data = d;
    next = n;
  }

  int GetData() {
    return data;
  }
  Node* GetNext() {
    return next;
  }

  void SetData(int d) {
    data = d;
  }
  void SetNext(Node* n) {
    next = n;
  }
};

class LinkedList {
private:
  Node* head,
      * tail;
public:
  LinkedList() {
    head = NULL;
    tail = NULL;
  }

  void InsertBeg(int d) {
    Node* newNode = new Node(d);
    newNode->SetNext(head);
    head = newNode;
    if(tail == NULL) {
      tail = head;
    }
    else {
      tail->SetNext(tail->GetNext());
    }
  }

  void print() {
    Node* tmp = head;
    while(tmp) {
      cout << tmp->GetData() << ' ';
      tmp = tmp->GetNext();
    }
    cout << endl;
    return;
  }
};

int main(void) {
  LinkedList my_list;
  size_t list_size;
  cin >> list_size;
  for(unsigned int i = 0; i < list_size; i++) {
    int tmp;
    cin >> tmp;
    my_list.InsertBeg(tmp);
  }
  my_list.print();
  return 0;
