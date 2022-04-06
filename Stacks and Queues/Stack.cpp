//
// Created by ahmad on 1/9/2022.
//

#include "Stack.h"

Stack :: Stack(){
    q1 = Queue();
    q2 = Queue();
}

void Stack::push(char val) {
    while (!q1.isEmpty()){
        q2.enqueue(q1.front());
        q1.dequeue();
    }
    q1.enqueue(val);
    while (!q2.isEmpty()){
        q1.enqueue(q2.front());
        q2.dequeue();
    }
}
char Stack::top() {
    if(!isEmpty()){
        return q1.front();
    }
    return 0;
}
bool Stack::isEmpty() {
    if(q1.isEmpty()){
        return true;
    }
    return false;
}
void Stack::clear() {
    q1.clear();
    q2.clear();
}
bool Stack::pop(){
    if(!isEmpty()){
        q1.dequeue();
        return true;
    }
    return false;
}
