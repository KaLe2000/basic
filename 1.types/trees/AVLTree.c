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
    return root != NULL
    ? root->height
    : 0;
}

// Функция корректировки высоты заданного узла
// разница между высотами левого и правого поддерева не может быть больше 1 
void updateHeight(node* root) {
    if (root != NULL) {
        root->height = 1 + (
            height(root->left) > height(root->right)
                ? height(root->left)
                : height(root->right)
            );
    }
}

node* rightRotate(node* y) {
    node* x = y->left;
    node* z = x->right;

    // Выполнение поворота
    x->right = y;
    y->left = z;

    // Обновление высот
    updateHeight(y);
    updateHeight(x);

    return x;  // Новый корень
}

node* leftRotate(node* x) {
    node* y = x->right;
    node* z = y->left;

    // Выполнение поворота
    y->left = x;
    x->right = z;

    // Обновление высот
    updateHeight(x);
    updateHeight(y);

    return y;  // Новый корень
}

int getBalance(node* root) {
    return root != NULL
    ? height(root->left) - height(root->right)
    : 0;
}

node* balance(node* root) {
    // Получаем баланс узла
    int balanceFactor = getBalance(root);

    // Левый тяжелый случай (лево-левый)
    if (balanceFactor > 1 && root->value > root->left->value) {
        return rightRotate(root);
    }

    // Правый тяжелый случай (право-правый)
    if (balanceFactor < -1 && root->value < root->right->value) {
        return leftRotate(root);
    }

    // Лево-правый случай
    if (balanceFactor > 1 && root->value < root->left->value) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Право-левый случай
    if (balanceFactor < -1 && root->value > root->right->value) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;  // Возвращаем неизмененный узел
}

node* insert(node* root, int value) {
    // Выполняем обычную вставку
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        // Ключ уже существует, ничего не делаем
        return root;
    }

    // Обновляем высоту узла
    updateHeight(root);

    // Балансируем дерево
    return balance(root);
}

node* findNode(node* root, int value) {
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->value)
    {
        return findNode(root->left, value);
    }

    if (value > root->value)
    {
        return findNode(root->right, value);
    }

    return root;
}

// Функция для обхода дерева в симметричном порядке
// аргументом функции является указатель с типом struct Node
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("val:%d, height:%d\n", root->value, root->height);
        inorderTraversal(root->right);
    }
}


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