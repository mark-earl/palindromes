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
        Queue(int);

        // copy constructor
        Queue(const Queue& obj);

        // destructor
        ~Queue();

        // queue operations
        void enqueue(T);
        T dequeue();
        T front() const;
        bool isEmpty() const;
        int getSize() const;
};

#endif // QUEUE_HPP
