//
// Created by ahmad on 1/9/2022.
//

#ifndef HW3_STACK_H
#define HW3_STACK_H
#include "Queue.h"
class Stack{
private:
    Queue q1;
    Queue q2;
public:
    Stack ();
    void push (char val);
    bool pop();
    char top ();
    bool isEmpty();
    void clear();
};

#endif //HW3_STACK_H
