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

// Функция создания узла с дефолтными параметрами
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

// Геттер высоты узла
int height(node* root) {
    return root
    ? root->height
    : 0;
}

// Функция корректировки высоты заданного узла
// разница между высотами левого и правого поддерева не может быть больше 1 
void updateHeight(node* root) {
    if (root) {
        root->height = 1 + (
            height(root->left) > height(root->right)
                ? height(root->left)
                : height(root->right)
            );
    }
}