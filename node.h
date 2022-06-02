#ifndef NODE_H
#define NODE_H

struct Node
{
    int value;
    int elements;
    Node *next;

    Node(int _value, Node *_next = nullptr) : value(_value), next(_next) {}
};

#endif