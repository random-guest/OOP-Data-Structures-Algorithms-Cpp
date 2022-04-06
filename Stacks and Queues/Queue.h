//
// Created by ahmad on 1/9/2022.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
struct Node{
    char val;
    Node* next;
    Node (char value){
        val = value;
        next = nullptr;
    }
};
class Queue {
private:
    Node * head;
    Node * tail;
public:
    Queue();
    void enqueue (char val);
    bool dequeue () ; // could be void as well
    char front ();
    bool isEmpty();
    void clear();
};

#endif //HW3_QUEUE_H
