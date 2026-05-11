#ifndef AVL_H
#define AVL_H

#include "Student.h"
#include <iostream>
#include <algorithm>

struct Node {
    Student data;
    Node *left;
    Node *right;
    int height;

    Node(Student s) : data(s), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;
    int nodeCount;

    int getHeight(Node* n);
    int getBalance(Node* n);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, Student s);
    void inOrder(Node* root, int &rank);

public:
    AVLTree() : root(nullptr), nodeCount(0) {}
    void insert(Student s);
    void displayRanking();
    void searchByScore(int score);
    void displayStats();
};

#endif // AVL_H