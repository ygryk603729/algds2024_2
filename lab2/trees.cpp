#include "trees.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node* CreateNode(int key, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->priority = priority;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

int getNodeValue(struct Node* node) {
    return node->key;
}

void printTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    int COUNT = 5;

    space += COUNT;

    printTree(root->right, space);
    printf("\n");

    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }

    printf("%d, %d\n", root->key, root->priority);

    printTree(root->left, space);
}

void rotateRight(Node* node) {
    Node* parent = node->parent;
    Node* grandparent = parent->parent;
    if (grandparent) {
        if (grandparent->left == parent) {
            grandparent->left = node;
        }
        else {
            grandparent->right = node;
        }
    }
    parent->left = node->right;
    if (node->right) {
        node->right->parent = parent;
    }
    node->right = parent;
    parent->parent = node;
    node->parent = grandparent;
}

void rotateLeft(Node* node) {
    Node* parent = node->parent;
    Node* grandparent = parent->parent;
    if (grandparent) {
        if (grandparent->left == parent) {
            grandparent->left = node;
        }
        else {
            grandparent->right = node;
        }
    }
    parent->right = node->left;
    if (node->left) {
        node->left->parent = parent;
    }
    node->left = parent;
    parent->parent = node;
    node->parent = grandparent;
}

void insert(Node** root, int key, int priority) {
    Node* newNode = �reateNode(key, priority);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* parent = NULL;
    Node* current = *root;
    while (current) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (key < parent->key) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }
    newNode->parent = parent;

    while (newNode->parent && newNode->priority > newNode->parent->priority) {
        if (newNode->parent->left == newNode) {
            rotateRight(newNode);
        }
        else {
            rotateLeft(newNode);
        }
    }
}

void mergeTrees(Node** t1, Node** t2) {
    // ������� ���� treaps
    Node* newRoot = NULL;
    while (*t1 && *t2) {
        if ((*t1)->priority > (*t2)->priority) {
            insert(&newRoot, (*t1)->key, (*t1)->priority);
            *t1 = (*t1)->right;
        }
        else {
            insert(&newRoot, (*t2)->key, (*t2)->priority);
            *t2 = (*t2)->right;
        }
    }

    while (*t1) {
        insert(&newRoot, (*t1)->key, (*t1)->priority);
        *t1 = (*t1)->right;
    }

    while (*t2) {
        insert(&newRoot, (*t2)->key, (*t2)->priority);
        *t2 = (*t2)->right;
    }

    *t1 = newRoot;
}

void splitTrees(Node** root, Node** root1, Node** root2, int key) {
    //insert(root, key, INT_MAX);
    //printTree(*root, 0);
    if ((*root)->key == key) {
        (*root1) = (*root)->left;
        (*root2) = (*root)->right;
        if ((*root1) != NULL) {
            (*root1)->parent = NULL;
        }
        if ((*root2) != NULL) {
            (*root2)->parent = NULL;
        }
    }
    else if ((*root)->key < key) {
        (*root1) = (*root);
        (*root2) = (*root)->right;
        (*root1)->right = NULL;
        if ((*root2) != NULL) {
            (*root2)->parent = NULL;
        }
    }
    else {
        (*root1) = (*root)->left;
        (*root2) = (*root);
        (*root2)->left = NULL;
        if ((*root1) != NULL) {
            (*root1)->parent = NULL;
        }
    }
}

void AnswerTree(Node* root, int* result) {
    if (root == NULL) {
        return;
    }

    // ��������� ������ �������� ���� � ����������
    *result = *result * 10 + root->key;

    if (root->left != NULL) {
        AnswerTree(root->left, result);
    }

    if (root->right != NULL) {
        AnswerTree(root->right, result);
    }
}