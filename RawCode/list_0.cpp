
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
  Node* tail;
public:
  LinkedList():head(nullptr), tail(nullptr) {
  }

  Node* GetHead() {
    return head;
  }

  Node* GetTail() {
    return tail;
  }

  void InsertBeg(int d) {
    Node* newNode = new Node(d);
    newNode->SetNext(head);
    head = newNode;
    if(tail == nullptr) {
      tail = head;
    }
    return;
  }

  void InsertAfter(int d, Node* prev) {
    if(prev == nullptr || head == nullptr || tail == nullptr) {
      clog << "Modifying the head" << endl;
      head = new Node(d);
      tail = head;
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
      if(prev == tail) {
        tail = tail->GetNext();
      }
      return;
    }
  }

  void InsertEnd(int d) {
    Node* newNode = new Node(d);
    if(tail == nullptr) {
      clog << "Modifying the head" << endl;
      head = newNode;
      tail = newNode;
      return;
    }
    else {
      tail->SetNext(newNode);
      tail = tail->GetNext();
      return;
    }
  }

  void Append(int d) {
    Node* newNode = new Node(d);
    if(head == nullptr) {
      clog << "Modifying the head" << endl;
      head = newNode;
      tail = newNode;
      return;
    }
    else {
      Node* tmp = head;
      while(tmp->GetNext()) {
        tmp = tmp->GetNext();
      }
      tmp->SetNext(newNode);
      tail = tmp->GetNext();
    }
  }

  bool DeleteFirst(int key) {
    if(head == nullptr) {
      return false;
    }
    else {
      Node* tmp = head;
      Node* prev = nullptr;
      while(tmp != nullptr && tmp->GetData() != key) {
        prev = tmp;
        tmp = tmp->GetNext();
      }
      if(tmp == nullptr) {
        return false;
      }
      else {
        if(tmp == head) {
          head = head->GetNext();
        }
        else if(tmp == tail) {
          // move last to prev;
          tail = prev;
          tail->SetNext(nullptr);
        }
        else {
          prev->SetNext(tmp->GetNext());
        }
        delete tmp;
        return true;
      }
    }
  }

  int DelAll(Node* prev, Node* cur, int key) {
    int ct = 0;
    Node* new_prev = nullptr;
    Node* new_cur = nullptr;
    if(cur == nullptr) {
      return 0;
    }
    else if(cur->GetData() == key) {
      // delete
      Node* tmp = cur;

      if(tmp == head) {
        head = head->GetNext();
        new_prev = nullptr;
        new_cur = head;
      }
      else if(tmp == tail) {
        tail = prev;
        new_prev = prev;
        new_cur = nullptr;
        prev->SetNext(nullptr);
      }
      else {
        new_prev = prev;
        prev->SetNext(tmp->GetNext());
        new_cur = prev->GetNext();
      }
      delete tmp;
      ct ++;

      cur = prev;
    }
    else {
      new_prev = cur;
      new_cur = cur->GetNext();
    }
    return (ct + DelAll(new_prev, new_cur, key));
  }

  int DeleteAll(int key) {
    if(head == nullptr) {
      return 0;
    }
    else {
      return DelAll(nullptr, head, key);
    }
  }

  // pos values [0, size - 1]
  bool DelPosition(int pos) {
    if(head == nullptr || pos < 0) {
      return false;
    }
    else if(pos == 0) {
      Node* cur = head;
      head = head->GetNext();
      delete cur;
      return true;
    }
    else {
      Node* prev = nullptr;
      Node* cur = head;
      for(int i = 0; i < pos && cur != nullptr; i++) {
        prev = cur;
        cur = cur->GetNext();
      }
      if(cur == nullptr) {
        return false;
      }
      else {
        prev->SetNext(cur->GetNext());
        delete cur;
        return true;
      }
    }
  }

  size_t Size() {
    size_t x = 0;
    Node* cur = head;
    while(cur) {
      x ++;
      cur = cur->GetNext();
    }
    return x;
  }

  size_t CalcSize(Node* cur, size_t x) {
    if(cur == nullptr) {
      return x;
    }
    return CalcSize(cur->GetNext(), x+1);
  }

  size_t SizeRec() {
    size_t x = 0;
    Node* cur = head;
    return CalcSize(cur, x);
  }

  void Print() {
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
  my_list.Print();
  my_list.InsertAfter(1, my_list.GetHead());
  my_list.Print();
  my_list.InsertEnd(7);
  my_list.Print();
  my_list.Append(8);
  my_list.Print();
  my_list.DeleteFirst(8);
  my_list.DeleteFirst(0);
  my_list.Print();
  my_list.InsertBeg(1);
  my_list.InsertEnd(1);
  my_list.InsertEnd(1);
  my_list.Print();
  cout << my_list.DeleteAll(1) << endl;
  my_list.Print();
  my_list.DelPosition(0);
  my_list.Print();
  cout << my_list.Size() << ' ' << my_list.SizeRec() << endl;
  return 0;
}
