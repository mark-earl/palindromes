/*
    Stack.hpp

    Interface file for the stack class
*/

#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class Stack
{
    private:
        // structure for stack nodes
        struct StackNode
        {
            // value in node
            T value;
            // pointer to the next node
            StackNode *next;
        };

        // number of elements in the stack
        int stackSize;
        // pointer to the top of the stack
        StackNode *topPtr;

    public:
        // constructor
        Stack() {topPtr = nullptr; stackSize = 0;}

        // destructor
        ~Stack()
        {
            clear();
            topPtr = nullptr;
        }

        // stack operations
        void clear();
        void push(T);
        T pop();

        bool isEmpty() const
        {
            return topPtr == nullptr;
        }

        int getSize() const
        {
            return stackSize;
        }
};

template <class T>
void Stack<T>::clear()
{
    StackNode *nodePtr;
    StackNode *nextNode;

    // position nodePtr at the top of the stack
    nodePtr = topPtr;
    // traverse the list deleting each node
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
        stackSize--;
    }
}

template <class T>
void Stack<T>::push(T item)
{
    // Pointer to a new node
    StackNode *newNode = nullptr;

    // Allocate a new node and store item there
    newNode = new StackNode;
    newNode->value = item;

    // if there are no nodes in the list, make newNode the first
    if (isEmpty())
    {
        topPtr = newNode;
        newNode->next = nullptr;
    }

    // otherwise, insert newNode before topPtr
    else
    {
        newNode->next = topPtr;
        topPtr = newNode;
    }

    stackSize++;
}

template <class T>
T Stack<T>::pop()
{
    StackNode *temp = nullptr;

    // make sure the stack is not empty
    if (isEmpty())
    {
        throw "The stack is empty.\n";
    }

    // otherwise, pop value off the stack
    else
    {
        T item = topPtr->value;
        temp = topPtr->next;
        delete topPtr;
        topPtr = temp;
        stackSize--;
        return item;
    }
}

#endif // STACK_HPP
