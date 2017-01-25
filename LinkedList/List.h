// List.h

#include <iostream>
#include <climits>
#include "Node.h"
using namespace std;

#ifndef List_h
#define List_h
class LinkedList {
 private:
  Node* head;

 public:
  LinkedList ();
  LinkedList (Node* head);
  LinkedList (const LinkedList& head);
  ~LinkedList ();
  void insertBeg (int data);
  void insertAfter (int data, Node* key_node);
  void insertBefore (int data, Node* key_node);
  void insertEnd (int data);
  void append (Node*);
  void deleteBeg ();
  void deleteNode (Node* key_node);
  void deleteEnd ();
  int deleteAll (int key);
  void printListR (Node* tmp);
  void printList ();
  size_t getSizeR (Node* tmp);
  size_t getSize ();
  Node* getHead ();
  Node* getFirst ();
  Node* getLast ();
  bool isEmpty ();
  bool isNotEmpty ();
  int getElement (int pos);
  bool contains (int key);
  bool containsR (Node* tmp, int key);
  void insertSorted (Node** sorted, int key);
  void insertionSort ();
};
inline Node* LinkedList::getFirst () { return this->getHead(); }
#endif
