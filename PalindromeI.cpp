/*
    PalindromeI.cpp

    Implementation file for the PalindromeI class
*/

#include "Queue.hpp"
#include "Stack.hpp"
#include "PalindromeI.hpp"
#include <string>

int PalindromeI::test_string(const std::string& s)
{
    // Queue<char> queue(s.length());
    // Stack<char> stack;

    // int numOfMatches = 0;

    // // add all of the characters to the stack and queue, front to back
    // for (char c:s)
    // {
    //     queue.enqueue(c);
    //     stack.push(c);
    // }

    // while (!stack.isEmpty() && !queue.isEmpty())
    // {
    //     if (stack.pop() != queue.dequeue())
    //     {
    //         stack.~Stack();
    //         queue.~Queue();
    //         return numOfMatches;
    //     }

    //     else
    //     {
    //         numOfMatches++;
    //     }
    // }

    return -1;
}
