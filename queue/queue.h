#ifndef queue_H
#define queue_H

#include <iostream>
#include <string>

using namespace std;

struct queue
{
    int data;
    queue *next;
};

bool isEmpty();
int peekFront();
void createQueue();
void enqueue(int data);
void dequeue();
void displayAll();
void clearQueue();
int peekRear();
bool isFull();
int currentSize();
int search(int value);
void replaceFront(int value);
void replaceRear(int value);

#endif