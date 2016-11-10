
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
using std::clog;
using std::cerr;
using std::endl;

class Node {
private:
  int data;
  Node* next;
public:
  Node():data(0), next(nullptr) {
  }
  Node(int d):data(d), next(nullptr) {
  }
  Node(int d, Node* n):data(d), next(n) {
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
  Node* last;
public:
  LinkedList():head(nullptr), last(nullptr) {
  }

  Node* GetHead() {
    return head;
  }

  Node* GetLast() {
    return last;
  }

  void InsertBeg(int d) {
    Node* newNode = new Node(d);
    newNode->SetNext(head);
    head = newNode;
    if(last == nullptr) {
      last = head;
    }
    return;
  }

  void InsertAfter(int d, Node* prev) {
    if(prev == nullptr || head == nullptr || last == nullptr) {
      clog << "Modifying the head" << endl;
      head = new Node(d);
      last = head;
      return;
    }
    else {
      // check if prev is valid
      Node* tmp = head;
      while(tmp != prev && tmp != nullptr) {
        tmp = tmp->GetNext();
      }
      if(tmp != prev) {
        cerr << "Previous Pointer not found" << endl;
        return;
      }
      Node* newNode = new Node(d, prev->GetNext());
      prev->SetNext(newNode);
      if(prev == last) {
        last = last->GetNext();
      }
      return;
    }
  }

  void InsertEnd(int d) {
    Node* newNode = new Node(d);
    if(last == nullptr) {
      clog << "Modifying the head" << endl;
      head = newNode;
      last = newNode;
      return;
    }
    else {
      last->SetNext(newNode);
      last = last->GetNext();
      return;
    }
  }

  void append(int d) {
    Node* newNode = new Node(d);
    if(head == nullptr) {
      clog << "Modifying the head" << endl;
      head = newNode;
      last = newNode;
      return;
    }
    else {
      Node* tmp = head;
      while(tmp->GetNext()) {
        tmp = tmp->GetNext();
      }
      tmp->SetNext(newNode);
      last = tmp->GetNext();
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
  my_list.InsertAfter(1, my_list.GetHead());
  my_list.print();
  my_list.InsertEnd(7);
  my_list.print();
  my_list.append(8);
  my_list.print();
  return 0;
}
