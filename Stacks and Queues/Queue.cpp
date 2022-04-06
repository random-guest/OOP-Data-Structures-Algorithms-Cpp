//
// Created by ahmad on 1/9/2022.
//

#include "Queue.h"
Queue::Queue() {
    head = nullptr;
    tail = nullptr;
}
void Queue::enqueue(char val) {
    Node* node = new Node(val);
    if(isEmpty()){
        head = node;
        tail = head;
    }
    else {
        tail->next = node;
        tail = tail->next;
    }
}
bool Queue::dequeue(){
    if(head == nullptr){
        return false;
    }
    head = head->next;
    if(head == nullptr){
        tail = nullptr;
    }
    return true;
}

char Queue::front() {
    if(head != nullptr){
        return head->val;
    }
    return 0;
}
bool Queue::isEmpty() {
    return head == nullptr && tail == nullptr;
}
void Queue::clear() {
    head = nullptr;
    tail = nullptr;
}
