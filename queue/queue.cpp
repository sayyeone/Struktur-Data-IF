#include "queue.h"

queue *frontNode = nullptr;
queue *rearNode = nullptr;

void createQueue()
{
    frontNode = nullptr;
    rearNode = nullptr;
}

bool isEmpty()
{
    return frontNode == nullptr;
}

void enqueue(int data)
{
    queue *newNode = new queue();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty())
    {
        frontNode = newNode;
        rearNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
        rearNode = newNode;
    }

    cout << "Data: " << rearNode->data << " Berhasil dimasukkan \n";
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue masih kosong! \n";
        return;
    }

    queue *temp = frontNode;
    cout << "Data: " << temp->data << " berhasil dihapus\n";
    frontNode = frontNode->next;

    if (frontNode == nullptr)
        rearNode = nullptr;

    delete temp;
}

int peekFront()
{
    if (isEmpty())
    {
        cout << "Queue masih kosong! \n";
        return -1;
    }

    return frontNode->data;
}

void displayAll()
{
    if (isEmpty())
    {
        cout << "Queue masih kosong! \n";
        return;
    }

    queue *temp = frontNode;
    cout << "Isi node dari depan -> belakang: \n";
    while (temp != nullptr)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

void clearQueue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

int peekRear()
{
    if (isEmpty())
    {
        cout << "Queue masih kosong!\n";
        return -1;
    }
    return rearNode->data;
}

bool isFull()
{
    return false;
}

int currentSize()
{
    int count = 0;
    queue *temp = frontNode;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int search(int value)
{
    queue *temp = frontNode;
    int indeks = 1;

    while (temp != nullptr)
    {
        if (temp->data == value)
            return indeks;

        temp = temp->next;
        indeks++;
    }

    return 0;
}

void replaceFront(int value)
{
    if (isEmpty())
    {
        cout << "Queue masih kosong!\n";
        return;
    }

    frontNode->data = value;
}

void replaceRear(int value)
{
    if (isEmpty())
    {
        cout << "Queue masih kosong!\n";
        return;
    }

    rearNode->data = value;
}
