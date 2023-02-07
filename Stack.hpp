/*
    Stack.hpp

    Interface file AND implementation (because template class) for the stack class
*/

#ifndef STACK_HPP
#define STACK_HPP

// template class allows for flexibility regarding the data it will store
// this queue is implemented via a linked list (it grows and shrink in size)
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
            // deallocate memory
            clear();

            // handle dangling pointer
            topPtr = nullptr;
        }

        // stack operations

        // deallocates memory
        void clear();

        // add an item
        void push(T);

        // remove an item
        T pop();

        // check if the stack is empty
        bool isEmpty() const
        {
            return topPtr == nullptr;
        }
};

// deallocates the memory used by the linked list
template <class T>
void Stack<T>::clear()
{
    // for current node
    StackNode *nodePtr;

    // for next node
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

// add item to the stack
template <class T>
void Stack<T>::push(T item)
{
    // pointer to a new node
    StackNode *newNode = nullptr;

    // allocate a new node and store item there
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

    // increase the stack size either way
    stackSize++;
}

// remove an element from the stack
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
