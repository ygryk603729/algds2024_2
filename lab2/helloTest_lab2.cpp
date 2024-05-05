// helloTest_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "trees.h"

int main()
{
    Node* treap1 = NULL;
    Node* treap2 = NULL;
    Node* treap3 = NULL;

    Node* treap4 = NULL;
    Node* treap5 = NULL;

    insert(&treap1, 5, 10);
    insert(&treap1, 2, 8);
    insert(&treap1, 8, 7);
    insert(&treap1, 1, 6);

    insert(&treap2, 7, 9);
    insert(&treap2, 2, 5);
    insert(&treap2, 8, 8);

    insert(&treap3, 7, 20);
    insert(&treap3, 2, 9);
    insert(&treap3, 8, 12);
    insert(&treap3, 6, 11);


    printf("1 tree:");
    printTree(treap1, 0);
    printf("\n2 tree:");
    printTree(treap2, 0);
    printf("\n3 tree:");
    printTree(treap3, 0);

    splitTrees(&treap3, &treap4, &treap5, 6);
    printf("\nSplited tree:");
    printTree(treap5, 0);

    mergeTrees(&treap1, &treap2);
    printf("\nMerged tree:");
    printTree(treap1, 0);

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
