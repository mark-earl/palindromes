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

        // copy constructor
        Stack(const Stack& obj);

        // destructor
        ~Stack()
        {
            clear();
        }

        // stack operations
        void clear();
        void push(T);
        T pop();
        T top() const;

        bool isEmpty() const
        {
            return topPtr == nullptr;
        }

        int getSize() const
        {
            return stackSize;
        }
};

#endif // STACK_HPP
