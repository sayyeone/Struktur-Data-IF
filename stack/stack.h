#ifndef stack_h
#define stack_h

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void createStack();
bool isEmpty();
void push(int data);
void pop();
void peek();
void displayAll();
int size();
void clear();
int search(int value);
void replaceTop(int val);
int bottom();

#endif
