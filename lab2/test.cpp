#include "pch.h"
#include "C:\Users\ikane\source\repos\helloTest_lab2\trees.cpp"

TEST(InsertTest, 1) {
    Node* treap1 = NULL;

    insert(&treap1, 5, 10);
    insert(&treap1, 2, 8);
    insert(&treap1, 8, 7);
    insert(&treap1, 1, 6);

    printf("Test 1. Tree:");
    printTree(treap1, 0);

    int a = 0;
    AnswerTree(treap1, &a);
    EXPECT_EQ(5218, a);
    EXPECT_TRUE(true);
}

TEST(SplitTest, 1) {
    Node* treap1 = NULL;
    Node* treap2 = NULL;
    Node* treap3 = NULL;

    insert(&treap1, 5, 10);
    insert(&treap1, 2, 8);
    insert(&treap1, 8, 7);
    insert(&treap1, 1, 6);

    /*printf("Pre-Splited Tree:");
    printTree(treap1, 0); */

    splitTrees(&treap1, &treap2, &treap3, 6);

    printf("Test 2. Splited Tree:");
    printTree(treap2, 0);

    int a = 0;
    AnswerTree(treap2, &a);
    EXPECT_EQ(521, a);
    EXPECT_TRUE(true);
}

TEST(MergeTest, 1) {
    Node* treap1 = NULL;
    Node* treap2 = NULL;

    insert(&treap1, 1, 10);
    insert(&treap1, 3, 8);

    insert(&treap2, 6, 3);
    insert(&treap2, 7, 2);
    insert(&treap2, 9, 1);

    /*printf("1 tree:");
    printTree(treap1, 0);
    printf("\n2 tree:"); 
    printTree(treap2, 0); */

    mergeTrees(&treap1, &treap2);
    printf("Test 3. Merged tree:");
    printTree(treap1, 0);

    int a = 0;
    AnswerTree(treap1, &a);
    EXPECT_EQ(13679, a);
    EXPECT_TRUE(true);
}

TEST(High_priotity_case, 1) {
    //������ � ����������� ���� ��� � �����
    Node* treap1 = NULL;

    insert(&treap1, 5, 10);
    insert(&treap1, 2, 11);

    printf("Test 4. Tree:");
    printTree(treap1, 0);

    int a = 0;
    AnswerTree(treap1, &a);
    EXPECT_EQ(5, a);
    EXPECT_TRUE(true);
}

TEST(ValueTest, 1) {
    Node* treap1 = NULL;

    insert(&treap1, 5, 10);
    insert(&treap1, 2, 8);
    insert(&treap1, 8, 7);
    insert(&treap1, 1, 6);

    printf("Test 5. Tree:");
    printTree(treap1, 0);

    EXPECT_EQ(2, getNodeValue(treap1->left));
    EXPECT_TRUE(true);
}

TEST(ValueTest, 2) {
    Node* treap1 = NULL;
    Node* treap2 = NULL;

    insert(&treap1, 1, 10);
    insert(&treap1, 3, 8);

    insert(&treap2, 6, 3);
    insert(&treap2, 7, 2);
    insert(&treap2, 9, 1);

    mergeTrees(&treap1, &treap2);
    printf("Test 6. Merged tree:");
    printTree(treap1, 0);

    EXPECT_EQ(7, getNodeValue(treap1->right->right->right));
    EXPECT_TRUE(true);
}