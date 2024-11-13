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

/*// Функция создания дерева заданной глубины
node* createTree(node* root, int currentDepth, int maxDepth)*/

// Функция для освобождения памяти дерева (рекурсивно)
// todo для тестирования сетить в указатель NULL
void clearTree(node* root) {
    if (root != NULL) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
        // root = NULL;
    }
}

// Поиск ноды для Бинарного Дерева Поиска
node* findNodeBSTree(node* root, int value) {
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->value)
    {
        return findNodeBSTree(root->left, value);
    }

    if (value > root->value)
    {
        return findNodeBSTree(root->right, value);
    }

    return root;
}

// Функция подсчёта листьев дерева, где лист это нода не имеющая дочерних нод
int getCountLists(node* root) {
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return getCountLists(root->left) + getCountLists(root->right);
}

// Функция для обхода дерева в симметричном порядке
// аргументом функции является указатель с типом struct Node
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d\n", root->value);
        inorderTraversal(root->right);
    }
}

