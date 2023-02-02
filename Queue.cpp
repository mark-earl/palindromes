/*
    Queue.cpp

    Implementation file for the queue class
*/

#include "Queue.hpp"

template <class T>
Queue<T>::Queue(int size)
{
    queueArray = new T[size];
    queueSize = size;
    frontSubscript = -1;
    rearSubscript = -1;
    numItems = 0;
}

template <class T>
Queue<T>::Queue(const Queue& obj)
{
    // Allocate the queue size
    if (obj.queueSize > 0)
    {
        queueArray = new T[obj.queueSize];
    }

    else
    {
        queueArray = nullptr;
    }

    // Copy the other object's attributes
    queueSize = obj.queueSizes;
    frontSubscript = obj.frontSubscript;
    rearSubscript = obj.rearSubscript;
    numItems = obj.numItems;

    // Copy the other's object's queue array
    for (int count = 0; count < obj.queueSize; count++)
    {
        queueArray[count] = obj.queueArray[count];
    }
}

template <class T>
Queue<T>::~Queue()
{
    if (numItems > 0)
        delete [] queueArray;
}

template <class T>
void Queue<T>::enqueue(T item)
{
    if (numItems < queueSize)
    {
        // insert new item
        queueArray[rearSubscript] = item;

        // calculate the new rear position
        rearSubscript = (rearSubscript + 1) % queueSize;

        // update item count
        numItems++;
    }

    else
    {
        throw "The queue is full.\n";
    }
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw "The queue is empty.\n";
    }

    else
    {
        // retreive the front item
        T item = queueArray[frontSubscript];
        // move front
        frontSubscript = (frontSubscript + 1) % queueSize;
        // update item count
        numItems--;
        return item;
    }
}

template <class T>
T Queue<T>::front() const
{
    if (isEmpty())
    {
        throw "The queue is empty.\n";
    }

    else
    {
        return queueArray[frontSubscript];
    }
}
