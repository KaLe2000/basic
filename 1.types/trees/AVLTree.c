#include <stdio.h>
#include <stdlib.h>

// Структура узла для AVL-дерева
// Отличие от стандарного BST в значении height - значение высоты поддерева
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;  // Начальная высота узла

    return newNode;
}