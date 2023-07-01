/*******************************************************************************
* AUTHOR       : Dillon Welsh
* ASSIGNMENT 5 : Airport
* CLASS        : CS 8
* SECTION      : 33776
* DUE DATE     : 04/16/2021
*******************************************************************************/

#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>

using namespace std;

template <typename type>
class MyQueue
{
private:
    int size;
    int capacity;
    int topOfQueue;
    int bottomOfQueue;
    type *queueArray;

public:
    /***************************************************************************
    * CONSTRUCTOR  MyQueue
    *___________________________________________________________________________
    * This constructor constructs an empty MyQueue.
    ***************************************************************************/
    MyQueue();
    /***************************************************************************
    * DESTRUCTOR  MyQueue
    *___________________________________________________________________________
    * This destructor destructs an empty MyQueue.
    ***************************************************************************/
    ~MyQueue();
    /***************************************************************************
    * MUTATOR doubleCapacity
    *___________________________________________________________________________
    * Doubles the capacity of the queue
    ***************************************************************************/
    void doubleCapacity();
    /***************************************************************************
    * MUTATOR halfCapacity
    *___________________________________________________________________________
    * Halves the capacity of the queue
    ***************************************************************************/
    void halfCapacity();
    /***************************************************************************
    * MUTATOR enqueue
    *___________________________________________________________________________
    * Adds to the queue
    ***************************************************************************/
    void enqueue(const type value);
    /***************************************************************************
    * MUTATOR dequeue
    *___________________________________________________________________________
    * Removes from the queue
    ***************************************************************************/
    void dequeue();
    /***************************************************************************
    * ACCESSOR top
    *___________________________________________________________________________
    * Returns the top of the queue
    ***************************************************************************/
    type top() const;
    /***************************************************************************
    * ACCESSOR isEmpty
    *___________________________________________________________________________
    * Returns true if the queue is empty
    ***************************************************************************/
    bool isEmpty() const;
    /***************************************************************************
    * ACCESSOR currentSize
    *___________________________________________________________________________
    * Returns the current size of the queue
    ***************************************************************************/
    int currentSize() const;
    /***************************************************************************
    * ACCESSOR currentCapacity
    *___________________________________________________________________________
    * Returns the current capacity of the queue
    ***************************************************************************/
    int currentCapacity() const;
    /***************************************************************************
    * ACCESSOR printQueue
    *___________________________________________________________________________
    * Prints out the queues information
    ***************************************************************************/
    void printQueue() const;
};

/***************************************************************************
* CONSTRUCTOR  MyQueue
*___________________________________________________________________________
* This constructor constructs an empty MyQueue.
***************************************************************************/
template <typename type>
MyQueue<type>::MyQueue()
{
    this->size = 0;
    this->capacity = 1;
    this->topOfQueue = 0;
    this->bottomOfQueue = 0;
    this->queueArray = new type[capacity];
}

/***************************************************************************
* DESTRUCTOR  MyQueue
*___________________________________________________________________________
* This destructor destructs an empty MyQueue.
***************************************************************************/
template <typename type>
MyQueue<type>::~MyQueue()
{
    delete []this->queueArray;
    this->queueArray = nullptr;
}

/***************************************************************************
* MUTATOR doubleCapacity
*___________________________________________________________________________
* Doubles the capacity of the queue
***************************************************************************/
template <typename type>
void MyQueue<type>::doubleCapacity()
{
    type *temp = this->queueArray;
    this->capacity *= 2;
    this->queueArray = new type[this->capacity];

    for(int i = 0; i < (size + 1); i++)
    {
        this->queueArray[i] = temp[i];
    }

    delete []temp;
    temp = nullptr;
}

/***************************************************************************
* MUTATOR halfCapacity
*___________________________________________________________________________
* Halves the capacity of the queue
***************************************************************************/
template <typename type>
void MyQueue<type>::halfCapacity()
{
    type *temp = this->queueArray;
    this->capacity /= 2;
    this->queueArray = new type[this->capacity];

    for(int i = 0; i < (size + 1); i++)
    {
        this->queueArray[i] = temp[i];
    }

    delete []temp;
    temp = nullptr;
}

/***************************************************************************
* MUTATOR enqueue
*___________________________________________________________________________
* Adds to the queue
***************************************************************************/
template <typename type>
void MyQueue<type>::enqueue(const type value)
{
    if(this->size + 1 == this->capacity) this->doubleCapacity();

    this->queueArray[this->size] = value;
    this->size++;
    this->bottomOfQueue++;
}

/***************************************************************************
* MUTATOR dequeue
*___________________________________________________________________________
* Removes from the queue
***************************************************************************/
template <typename type>
void MyQueue<type>::dequeue()
{
    this->topOfQueue++;
    this->size--;
}

/***************************************************************************
* ACCESSOR top
*___________________________________________________________________________
* Returns the top of the queue
***************************************************************************/
template <typename type>
type MyQueue<type>::top() const
{
    return this->queueArray[this->topOfQueue];
}

/***************************************************************************
* ACCESSOR isEmpty
*___________________________________________________________________________
* Returns true if the queue is empty
***************************************************************************/
template <typename type>
bool MyQueue<type>::isEmpty() const
{
    return (this->size == 0);
}

/***************************************************************************
* ACCESSOR currentSize
*___________________________________________________________________________
* Returns the current size of the queue
***************************************************************************/
template <typename type>
int MyQueue<type>::currentSize() const
{
    return this->size;
}

/***************************************************************************
* ACCESSOR currentCapacity
*___________________________________________________________________________
* Returns the current capacity of the queue
***************************************************************************/
template <typename type>
int MyQueue<type>::currentCapacity() const
{
    return this->capacity;
}

/***************************************************************************
* ACCESSOR printQueue
*___________________________________________________________________________
* Prints out the queues information
***************************************************************************/
template <typename type>
void MyQueue<type>::printQueue() const
{
    for(int i = this->topOfQueue; i < this->bottomOfQueue; i++)
    {
        cout << this->queueArray[i] << endl;
    }
}

#endif // MYQUEUE_H
