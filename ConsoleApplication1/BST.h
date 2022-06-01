#pragma once

class BST {
private:
    int data;
    BST* left;
    BST* right;
public:
    BST();
    BST(int x);
    BST* Insert(BST* root, int x);
    void Inorder(BST* root);
    bool Search(BST* root, int x);
    BST* DeleteNode(BST* root, int key);
    BST* minValueNode(BST* root);
    void Mirror(BST* root);
    bool isBST(BST* root);
};