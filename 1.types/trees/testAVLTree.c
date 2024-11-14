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

int main()
{
    testCreateNode();

    return EXIT_SUCCESS;
}