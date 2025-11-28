#include "stack.h"

Node *top = nullptr;

void createStack()
{
    top = nullptr;
}

bool isEmpty()
{
    return top == nullptr;
}

void push(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }

    Node *oldTop = top;
    top = top->next;
    delete oldTop;
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    cout << "Top = " << top->data << endl;
}

void displayAll()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }

    Node *temp = top;
    cout << "Isi Stack (atas → bawah):\n";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int size()
{
    int count = 0;
    Node *temp = top;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void clear()
{
    while (!isEmpty())
    {
        pop();
    }
}

int search(int value)
{
    Node *temp = top;
    int indeks = 1;
    while (temp != nullptr)
    {
        if (temp->data == value)
            return indeks;
        temp = temp->next;
        indeks++;
    }
    return false;
}

void replaceTop(int val)
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return;
    }
    top->data = val;
}

int bottom()
{
    if (isEmpty())
    {
        cout << "Stack kosong!\n";
        return -1;
    }

    Node *temp = top;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp->data;
}
