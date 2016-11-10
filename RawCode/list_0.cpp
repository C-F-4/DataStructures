/*
 * Arrays - fixed size
 *        - better cache locality
 *        - faster read(searching)
 *        - slower write(insertion, deletion)
 * Linked List - dynamic size
 *        - poorer cache locality
 *        - slower read(searching)
 *        - a little faster write(insertion, deletion)
 *        - extra memory for next pointer references
 */

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
  Node* head;
public:
  LinkedList() {
    head = NULL;
  }

  void InsertBeg(int d) {
    Node* newNode = new Node(d);
    newNode->SetNext(head);
    head = newNode;
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
}
