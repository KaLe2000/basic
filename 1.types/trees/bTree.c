#include <stdio.h>
#include <stdlib.h>

// struct Node - структура узла
// typedef struct Node {} node; - альтернативное имя для структуры узла
// используется для удобства. вместо struct Node newNode используем node newNode
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} node;

// Функция для создания нового узла
// объявляет указатель для структуры Node, выделяет память размером struct Node
// возвращает указатель на память 
node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Функция для освобождения памяти дерева (рекурсивно)
void clearTree(node* root) {
    if (root != NULL) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}

// Функция для обхода дерева в симметричном порядке
// аргументом функции является указатель с типом struct Node
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

int main() {
    // node* tree = NULL;
    node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);

    // tree = createTree(tree, 1, 5); // node, currentDepth, maxDepth

    printf("Inorder Traversal: ");
    inorderTraversal(tree); // Вывод: 4 2 5 1 3
    clearTree(tree);

    return 0;
}
