#include "queue.h"
#include <iostream>

int main() {
    int n, k;
    if (!(std::cin >> n >> k)) return 0;

    int arr[105];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i <= n - k; i++) {
        Queue q;
        init(&q);
        int current_sum = 0;

        for (int j = i; j < i + k; j++) {
            enqueue(&q, arr[j]);
            current_sum += arr[j];
        }

        std::cout << current_sum;
        
        if (i < n - k) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}