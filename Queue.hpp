/*
    Queue.hpp

    Interface AND implementation (because template class) file for the queue class
*/

#ifndef QUEUE_HPP
#define QUEUE_HPP

// template class allows for flexibility regarding the data it will store
// this queue is implemented via a static array (it does not grow and shrink in size)
template <class T>
class Queue
{
    private:
        // points to the queue array
        T *queueArray;

        // the queue size
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

        // add elements
        void enqueue(T);

        // remove elements
        T dequeue();

        // test if the queue is empty
        bool isEmpty() const
        {
            return numItems == 0;
        }
};

// constructor
template <class T>
Queue<T>::Queue(int size)
{
    // allocate space for the array of the appropriate type
    queueArray = new T[size];

    // set the size
    queueSize = size;

    // initially -1, these get calculated in enqueue and dequeue when called
    frontSubscript = -1;
    rearSubscript = -1;

    // there are no items in the queue yet
    numItems = 0;
}

// destructor
template <class T>
Queue<T>::~Queue()
{
    // free the memory
    delete [] queueArray;

    // handle dangling pointer
    queueArray = nullptr;
}

// add item to the queue
template <class T>
void Queue<T>::enqueue(T item)
{
    // check if the queue is full
    if (numItems < queueSize)
    {
        // calculate the new rear position
        rearSubscript = (rearSubscript + 1) % queueSize;
        // insert new item
        queueArray[rearSubscript] = item;
        // update item count
        numItems++;
    }

    // can't add items to a full queue
    else
    {
        throw "The queue is full.\n";
    }
}

// remove items from the queue
template <class T>
T Queue<T>::dequeue()
{
    // check if the queue is empty
    if (isEmpty())
    {
        throw "The queue is empty.\n";
    }

    // if not, there are elements that can be removed
    else
    {
        // calculate the new front position
        frontSubscript = (frontSubscript + 1) % queueSize;
        // retrieve the front item
        T item = queueArray[frontSubscript];
        // update item count
        numItems--;
        // return the popped item
        return item;
    }
}

#endif // QUEUE_HPP
