#include "double_linked_list.h"
#include <iostream>

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(int val) {
    Node* newNode = new Node{(char)val, nullptr, nullptr};
    if (is_empty()) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    size++;
}

void DoubleLinkedList::add_back(int val) {
    if (is_empty()) {
        add_front(val);
        return;
    }
    Node* newNode = new Node{(char)val, head, tail};
    tail->next = newNode;
    head->prev = newNode;
    tail = newNode;
    size++;
}

void DoubleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) return;
    if (idx == 0) {
        add_front(val);
        return;
    }
    if (idx == size) {
        add_back(val);
        return;
    }

    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    
    Node* newNode = new Node{(char)val, curr, curr->prev};
    curr->prev->next = newNode;
    curr->prev = newNode;
    size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;
    Node* temp = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete temp;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;
    if (size == 1) {
        delete_front();
        return;
    }
    Node* temp = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) return;
    if (idx == 0) {
        delete_front();
        return;
    }
    if (idx == size - 1) {
        delete_back();
        return;
    }

    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    size--;
}

char DoubleLinkedList::get(int idx) {
    if (is_empty() || idx < 0 || idx >= size) return '\0';
    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (is_empty() || idx < 0 || idx >= size) return;
    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->data = val;
}

void DoubleLinkedList::display() {
    if (is_empty()) {
        std::cout << "EMPTY" << std::endl;
        return;
    }
    Node* curr = head;
    for (int i = 0; i < size; i++) {
        std::cout << curr->data;
        curr = curr->next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}