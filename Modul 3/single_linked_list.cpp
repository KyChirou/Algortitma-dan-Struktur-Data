#include "single_linked_list.h"
#include <iostream>

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return size == 0;
}

void SingleLinkedList::add_front(int val) {
    Node* newNode = new Node{val, nullptr};
    if (is_empty()) {
        head = tail = newNode;
        tail->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    Node* newNode = new Node{val, nullptr};
    if (is_empty()) {
        head = tail = newNode;
        tail->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) return;
    if (idx == 0) { add_front(val); return; }
    if (idx == size) { add_back(val); return; }

    Node* curr = head;
    for (int i = 0; i < idx - 1; i++) curr = curr->next;
    
    Node* newNode = new Node{val, curr->next};
    curr->next = newNode;
    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) return;
    Node* temp = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete temp;
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) return;
    if (size == 1) { delete_front(); return; }
    Node* curr = head;
    while (curr->next != tail) curr = curr->next;
    delete tail;
    tail = curr;
    tail->next = head;
    size--;
}

void SingleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) return;
    if (idx == 0) { delete_front(); return; }
    Node* curr = head;
    for (int i = 0; i < idx - 1; i++) curr = curr->next;
    Node* target = curr->next;
    curr->next = target->next;
    if (target == tail) tail = curr;
    delete target;
    size--;
}

int SingleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) return -1;
    Node* curr = head;
    for (int i = 0; i < idx; i++) curr = curr->next;
    return curr->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (idx < 0 || idx >= size) return;
    Node* curr = head;
    for (int i = 0; i < idx; i++) curr = curr->next;
    curr->data = val;
}

void SingleLinkedList::display() {
    if (is_empty()) return;
    Node* curr = head;
    for (int i = 0; i < size; i++) {
        std::cout << curr->data << (i == size - 1 ? "" : " ");
        curr = curr->next;
    }
    std::cout << std::endl;
}

void SingleLinkedList::clear() {
    while (!is_empty()) delete_front();
}