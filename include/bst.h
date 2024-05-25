// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
    struct Node {
        T value;
        int frequency;
        Node *left, *right;
    };
    Node* root;
    Node* insertNode(Node* current, const T& value) {
        if (current == nullptr) {
            current = new Node{value, 1, nullptr, nullptr};
        } else if (current->value > value) {
            current->left = insertNode(current->left, value);
        } else if (current->value < value) {
            current->right = insertNode(current->right, value);
        } else {
            current->frequency++;
        }
        return current;
    }
    int calculateHeight(Node* current) {
        return (current == nullptr) ? 0 : std::max(calculateHeight(current->left), calculateHeight(current->right)) + 1;
    }
    Node* findNode(Node* current, const T& value) {
        if (current == nullptr || current->value == value) return current;
        return (value < current->value) ? findNode(current->left, value) : findNode(current->right, value);
    }
 public:
    BST() : root(nullptr) {}
    void add(const T& value) { root = insertNode(root, value); }
    int depth() { return calculateHeight(root) - 1; }
    int search(const T& value) {
        Node* foundNode = findNode(root, value);
        return (foundNode == nullptr) ? 0 : foundNode->frequency;
    }
};

#endif  // INCLUDE_BST_H_
