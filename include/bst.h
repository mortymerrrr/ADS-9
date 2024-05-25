// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
 private:
    struct NODE {
        T value;
        int cnt;
        NODE *left, *right;
    };
    NODE* root;
    NODE* insertNODE(NODE* root, const T& value) {
        if (root == nullptr) {
            root = new NODE;
            root->value = value;
            root->cnt = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = insertNODE(root->left, value);
        } else if (root->value < value) {
            root->right = insertNODE(root->right, value);
        } else {
            root->cnt += 1;
        }
        return root;
    }
    int depthTree(NODE* root) {
        if (root == nullptr) return 0;
        return std::max(depthTree(root->left), depthtTree(root->right)) + 1;
    }
    NODE* searchTree(NODE* root, const T& value) {
        if (root == nullptr || root->value == value) return root;
        if (value < root->value) return searchTree(root->left, value);
        return searchTree(root->right, value);
    }
 public:
    BST() : root(nullptr) {}
    void insert(const T& value) { root = insertNODE(root, value); }
    int depth() { return depthTree(root) - 1; }
    int search(const T& value) {
        NODE* curr = searchTree(root, value);
        if (curr == nullptr) {
            return 0;
        } else {
            return curr->cnt;
        }
    }
};
#endif  // INCLUDE_BST_H_
