// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
    struct TreeNode {
        T value;
        int frequency;
        TreeNode *left, *right;
    };
    TreeNode* rootNode;

    TreeNode* insertNode(TreeNode* node, const T& value) {
        if (node == nullptr) {
            node = new TreeNode{value, 1, nullptr, nullptr};
        } else if (node->value > value) {
            node->left = insertNode(node->left, value);
        } else if (node->value < value) {
            node->right = insertNode(node->right, value);
        } else {
            node->frequency++;
        }
        return node;
    }

    int getHeight(TreeNode* node) {
        return (node == nullptr) ? 0 : std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    TreeNode* findNode(TreeNode* node, const T& value) {
        if (node == nullptr || node->value == value) return node;
        return (value < node->value) ? findNode(node->left, value) : findNode(node->right, value);
    }

 public:
    BST() : rootNode(nullptr) {}

    void insert(const T& value) { rootNode = insertNode(rootNode, value); }

    int getDepth() { return getHeight(rootNode) - 1; }

    int getFrequency(const T& value) {
        TreeNode* currentNode = findNode(rootNode, value);
        return (currentNode == nullptr) ? 0 : currentNode->frequency;
    }
};

#endif  // INCLUDE_BST_H_
