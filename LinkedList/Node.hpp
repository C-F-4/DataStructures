// Node.h

#ifndef Node_H
#define Node_H

class Node {
private:
    int data;
    Node* next;

public:
    /*
    ** Constructors && Destructors
    */
    Node ();

    Node (int);

    Node (int, Node*);

    Node (const Node&);

    ~Node ();

    /*
    ** Setter Methods
    */
    void setData (int);

    void setNext (Node*);

    /*
    ** Getter Methods
    */
    int getData ();

    Node* getNext ();
};

#endif
