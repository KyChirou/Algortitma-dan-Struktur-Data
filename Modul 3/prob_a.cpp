#include "single_linked_list.h"
#include <iostream>

int main() {
    int N;
    long long K, initialK;
    if (!(std::cin >> N >> K)) return 0;
    initialK = K;
    SingleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        list.add_back(val);
    }

    int currentIndex = 0;
    while (list.size > 1) {
        currentIndex = (currentIndex + (K - 1)) % list.size;
        int val = list.get(currentIndex);

        if (val % 2 == 0) {
            K++;
        } else {
            K--;
        }

        if (K <= 0) {
            K = initialK;
        }

        list.delete_idx(currentIndex);
        if (currentIndex >= list.size) {
            currentIndex = 0;
        }
    }

    std::cout << list.get(0) << std::endl;
    list.clear();
    return 0;
}