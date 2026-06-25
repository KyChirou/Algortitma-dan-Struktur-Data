#include <iostream>
#include <string>
#include "RedBlackTree.h"
using namespace std;

void printPreorder(const RedBlackTree::Node* node) {
    if (node == nullptr || node->isNil) return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

void printInorder(const RedBlackTree::Node* node) {
    if (node == nullptr || node->isNil) return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

void printPostorder(const RedBlackTree::Node* node) {
    if (node == nullptr || node->isNil) return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}

int main() {
    int N;
    if (!(cin >> N)) return 0;

    RedBlackTree tree;

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (!tree.contains(val)) {
            tree.insert(val);
        }
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string query;
        cin >> query;

        if (tree.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
            continue;
        }

        if (query == "PREORDER" || query == "ALL") {
            cout << "[Preorder] : ";
            printPreorder(tree.root());
            cout << "\n";
        }
        
        if (query == "INORDER" || query == "ALL") {
            cout << "[Inorder]  : ";
            printInorder(tree.root());
            cout << "\n";
        }
        
        if (query == "POSTORDER" || query == "ALL") {
            cout << "[Postorder]: ";
            printPostorder(tree.root());
            cout << "\n";
        }
    }

    return 0;
}