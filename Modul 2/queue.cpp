#include "queue.h"
#include <iostream>
#include <stdexcept>

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    if (isEmpty(q)) return false;
    return (q->front == &(q->data[0]) && q->rear == &(q->data[MAX - 1]));
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        throw std::out_of_range("Queue Overflow");
    }

    if (isEmpty(q)) {
        q->front = &(q->data[0]);
        q->rear = &(q->data[0]);
        *(q->rear) = value;
    } 
    else if (q->rear == &(q->data[MAX - 1])) {
        int size = q->rear - q->front + 1;
        for (int i = 0; i < size; i++) {
            q->data[i] = q->front[i];
        }
        q->front = &(q->data[0]);
        q->rear = &(q->data[size - 1]);
        
        q->rear++;
        *(q->rear) = value;
    } 
    else {
        q->rear++;
        *(q->rear) = value;
    }
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        throw std::out_of_range("Queue Underflow");
    }

    if (q->front == q->rear) {
        q->front = nullptr;
        q->rear = nullptr;
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) {
        throw std::out_of_range("Queue is Empty");
    }
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q)) {
        throw std::out_of_range("Queue is Empty");
    }
    return *(q->rear);
}