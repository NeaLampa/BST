#include <iostream>
#include "BST.h"

int main()
{
    BST b, * root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);
    std::cout << "\n";

    if (b.Search(root, 100))
        std::cout << "exista\n";
    else
        std::cout << "nu exista\n";

    b.DeleteNode(root, 80);

    b.Inorder(root);
    std::cout << "\n";

    b.Mirror(root);

    b.Inorder(root);
    std::cout << "\n";

    std::cout << b.isBST(root) << "\n";

    b.Mirror(root);

    b.Inorder(root);
    std::cout << "\n";

    std::cout << b.isBST(root);

    return 0;
}