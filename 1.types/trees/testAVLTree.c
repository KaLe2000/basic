#include <stdio.h>
#include <stdlib.h>
#include "AVLTree.c"

void testCreateNode() {
    node* root = createNode(1);

    if (root->value == 1 && root->height == 1)
    {
        printf("testCreateNode() is success\n");
    } else {
        printf("testCreateNode() is failed\n");
    }

    free(root);
}

void testHeight() {
    node* root = createNode(20);

    if (height(root) == 1)
    {
        printf("testHeight() is success\n");
    } else {
        printf("testHeight() is failed\n");
    }

    free(root);
}

void testUpdateHeight() {
    node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);

    updateHeight(root);

    if (height(root) == 2)
    {
        printf("testUpdateHeight() is success\n");
    } else {
        printf("testUpdateHeight() is failed\n");
    }

    free(root);
}

void testInsert() {
    node* root = NULL;

    // Вставка данных
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 70);
    root = insert(root, 90);
    root = insert(root, 5);

    node* resultNode = findNode(root, 30);
    if (resultNode->height == 4)
    {
        printf("testInsert() is success\n");
    } else {
        printf("testInsert() is failed\n");
    }

    clearTree(root);
}

// https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
int main()
{
    testCreateNode();
    testHeight();
    testUpdateHeight();
    testInsert();

    return EXIT_SUCCESS;
}