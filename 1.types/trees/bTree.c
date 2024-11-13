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
void clearTree(node* root) {
    if (root != NULL) {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
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

// Функция для обхода дерева в симметричном порядке
// аргументом функции является указатель с типом struct Node
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d\n", root->value);
        inorderTraversal(root->right);
    }
}

int main() {
    node* tree = createNode(1);
    tree->left = createNode(2);
    tree->right = createNode(3);
    tree->left->left = createNode(4);
    tree->left->right = createNode(5);

    printf("Inorder Traversal: ");
    inorderTraversal(tree); // Вывод: 4 2 5 1 3
    clearTree(tree);

    node* bsTree = createNode(20);

    bsTree->left = createNode(10);
    bsTree->left->left = createNode(5);
    bsTree->left->right = createNode(15);

    bsTree->right = createNode(30);
    bsTree->right->left = createNode(25);
    bsTree->right->right = createNode(35);

    inorderTraversal(bsTree);  // Вывод: 5 10 15 20 25 30 35

    node* resultNode = findNodeBSTree(bsTree, 15);
    printf("%d bsTree\n", resultNode->value);
    clearTree(bsTree);

    return EXIT_SUCCESS;
}
