#include <stdio.h>
#include <stdlib.h>
#include "BSTree.c"

void testCreateNode() {
    int assertVal = 1;
    node* root = createNode(assertVal);

    if (root->value == assertVal)
    {
        printf("testCreateNode success\n");
    } else {
        printf("testCreateNode failed\n");
    }

    clearTree(root);
}

void testClearTree() {
    node* root = createNode(1);
    clearTree(root);

    if (root == NULL)
    {
        printf("testClearTree success\n");
    } else {
        printf("testClearTree failed\n");
    }
}

void testFindNodeBSTree() {
    int assertVal = 15;
    node* bsTree = createNode(20);

    bsTree->left = createNode(10);
    bsTree->left->left = createNode(5);
    bsTree->left->right = createNode(assertVal);

    bsTree->right = createNode(30);
    bsTree->right->left = createNode(25);
    bsTree->right->right = createNode(35);

    node* resultNode = findNodeBSTree(bsTree, assertVal);

    if (resultNode->value == assertVal)
    {
        printf("testFindNodeBSTree success\n");
    } else {
        printf("testFindNodeBSTree failed\n");
    }

    clearTree(bsTree);
}

void testGetCountLists() {
    int assertVal = 4;
    node* bsTree = createNode(20);

    bsTree->left = createNode(10);
    bsTree->left->left = createNode(5);
    bsTree->left->right = createNode(15);

    bsTree->right = createNode(30);
    bsTree->right->left = createNode(25);
    bsTree->right->right = createNode(35);

    int result = getCountLists(bsTree);

    if (result == assertVal)
    {
        printf("testGetCountLists success\n");
    } else {
        printf("testGetCountLists failed\n");
    }
}

int main() {
    testCreateNode();
    // testClearTree(); // see todo clearTree()
    testFindNodeBSTree();
    testGetCountLists();

    return EXIT_SUCCESS;
}