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

int main()
{
    testCreateNode();
    testHeight();
    testUpdateHeight();

    return EXIT_SUCCESS;
}