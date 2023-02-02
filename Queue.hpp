/*
    Queue.hpp

    Interface file for the queue class
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

template <class T>
class Queue
{
    private:
        // Points to the queue array
        T *queueArray;

        // The queue size
        int queueSize;

        // subscript of the queue front
        int frontSubscript;

        // subscript of the queue rear
        int rearSubscript;

        // number of items in the queue
        int numItems;

    public:
        // constructor
        Queue(int size);

        // destructor
        ~Queue();

        // queue operations
        void enqueue(T);
        T dequeue();
        bool isEmpty() const
        {
            return numItems == 0;
        }
        int getSize() const
        {
            return numItems;
        }
};

// Constructor
template <class T>
Queue<T>::Queue(int size)
{
    queueArray = new T[size];
    queueSize = size;
    frontSubscript = -1;
    rearSubscript = -1;
    numItems = 0;
}

// Destructor
template <class T>
Queue<T>::~Queue()
{
    if (numItems > 0)
        delete [] queueArray;
    queueArray = nullptr;
}

template <class T>
void Queue<T>::enqueue(T item)
{
    // Check if the queue is full
    if (numItems < queueSize)
    {
        // calculate the new rear position
        rearSubscript = (rearSubscript + 1) % queueSize;
        // insert new item
        queueArray[rearSubscript] = item;
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
    // Check if the queue is empty
    if (isEmpty())
    {
        throw "The queue is empty.\n";
    }

    else
    {
        // move front
        frontSubscript = (frontSubscript + 1) % queueSize;
        // retreive the front item
        T item = queueArray[frontSubscript];
        // update item count
        numItems--;
        return item;
    }
}
#endif // QUEUE_HPP
