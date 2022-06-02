#include "node.h"
#include <iostream>
#ifndef STACK_H
#define STACK_H

class Stack
{
    Node *head;

public:
    Stack() : head(nullptr){};

    void push(int x)
    {
        head = new Node(x, head);
    }

    bool empty() const
    {
        return head == nullptr;
    }

    int top() const
    {
        if (empty())
        {
            throw std::runtime_error("Stack is empty");
        }
        return head->value;
    }
    void pop()
    {
        if (empty())
        {
            throw std::runtime_error("Stack is empty");
        }
        pop_unsafe();
    }
    void clear()
    {
        while (!empty())
        {
            pop_unsafe();
        }
    }
    ~Stack()
    {
        clear();
    }
    Stack(const Stack &original) : head(nullptr)
    {
        if (!original.empty())
        {
            head = new Node(original.head->value);
            Node *src = original.head->next;
            Node *dst = head;

            while (src != nullptr)
            {
                dst->next = new Node(src->value);
                src = src->next;
                dst = dst->next;
            }
        }
    }

    Stack &operator=(Stack cpy)
    {
        std::swap(cpy.head, head);
        return *this;
    }

    void print()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            std::cout << tmp->value << " , ";
            tmp = tmp->next;
        }
    }

    Stack &operator+(Stack &other)
    {
        // idk how to do it
    }

    void nth(int n)
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->elements == n)
            {
                std::cout << tmp->value << " , ";
            }
            tmp = tmp->next;
        }
    }

private:
    void pop_unsafe()
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
};
#endif