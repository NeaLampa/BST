#include <iostream>
#include "BST.h"

BST::BST() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}
BST::BST(int x) {
    this->data = x;
    this->left = this->right = NULL;
}
BST* BST::Insert(BST* root, int x) {
    if (!root) {
        return new BST(x);
    }
    if (x > root->data) {
        root->right = Insert(root->right, x);
    }
    else {
        root->left = Insert(root->left, x);
    }
    return root;
}
void BST::Inorder(BST* root) {
    if (!root) {
        return;
    }
    Inorder(root->left);
    std::cout << root->data << " ";
    Inorder(root->right);
}
bool BST::Search(BST* root, int x) {
    if (!root)
        return false;
    if (root->data == x)
        return true;
    if (root->data > x)
        return Search(root->left, x);
    if (root->data < x)
        return Search(root->right, x);
}
BST* BST::minValueNode(BST* root) {
    BST* temp = root;
    while (temp && temp->left != NULL)
        temp = temp->left;
    return temp;
}
BST* BST::DeleteNode(BST* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = DeleteNode(root->left, key);
    else if (key > root->data)
        root->right = DeleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            free(root);
            return temp;
        }
        BST* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = DeleteNode(root->right, temp->data);
    }
    return root;
}
void BST::Mirror(BST* root) {
    if (root == NULL)
        return;
    else {
        BST* temp = NULL;
        Mirror(root->left);
        Mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
bool BST::isBST(BST* root) {
    if (root == NULL)
        return true;
    if (root->left != NULL && root->left->data > root->data)
        return false;
    if (root->right != NULL && root->right->data < root->data)
        return false;
    if (!isBST(root->left) || !isBST(root->right))
        return false;
    return true;
}
