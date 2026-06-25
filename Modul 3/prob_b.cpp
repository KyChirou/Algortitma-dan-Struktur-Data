#include "double_linked_list.h"
#include <iostream>

int main() {
    int N, R;
    if (!(std::cin >> N >> R)) return 0;
    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        char c;
        std::cin >> c;
        list.add_back(c);
    }

    Node* alpha = list.head;
    Node* beta = list.tail;

    for (int i = 0; i < R; i++) {
        long long X, Y;
        std::cin >> X >> Y;
        if (list.is_empty()) continue;

        long long moveAlpha = X % list.size;
        for (long long j = 0; j < moveAlpha; j++) {
            alpha = alpha->next;
        }

        long long moveBeta = Y % list.size;
        for (long long j = 0; j < moveBeta; j++) {
            beta = beta->prev;
        }

        if (alpha == beta) {
            Node* target = alpha;
            alpha = target->next;
            beta = target->prev;

            Node* temp = list.head;
            int idx = 0;
            while (temp != target) {
                temp = temp->next;
                idx++;
            }
            list.delete_idx(idx);

            if (list.size == 0) {
                alpha = beta = nullptr;
            }
        } 
        else if (alpha->next == beta || beta->next == alpha) {
            char tempVal = alpha->data;
            alpha->data = beta->data;
            beta->data = tempVal;
        }
    }

    list.display(); 
    list.clear();
    return 0;
}