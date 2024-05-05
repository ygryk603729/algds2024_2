#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int key;
    int priority;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

Node* createNode(int key, int priority);
void printTree(Node* root, int space);

void rotateRight(Node* node);
void rotateLeft(Node* node);

void insert(Node** root, int key, int priority);
void mergeTrees(Node** t1, Node** t2);

void splitTrees(Node** root, Node** root1, Node** root2, int key);

void AnswerTree(Node* root, int* result);