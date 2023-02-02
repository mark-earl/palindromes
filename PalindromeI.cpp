/*
    PalindromeI.cpp

    Implementation file for the PalindromeI class
*/

#include "Queue.hpp"
#include "Stack.hpp"
#include "PalindromeI.hpp"
#include <string>
#include <algorithm>

int PalindromeI::test_string(std::string s)
{
    // remove capital letters
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    // remove punctuation
    s.erase (std::remove_if (s.begin (), s.end (), ispunct), s.end ());
    // remove spaces
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());

    Queue<char> queue(s.length());
    Stack<char> stack;

    int numOfMatches = 0;

    // add all of the characters to the stack and queue, front to back
    for (char c:s)
    {
        queue.enqueue(c);
        stack.push(c);
    }

    while (!stack.isEmpty() && !queue.isEmpty())
    {
        if (stack.pop() != queue.dequeue())
        {
            stack.~Stack();
            queue.~Queue();
            return numOfMatches;
        }

        else
        {
            numOfMatches++;
        }
    }
    return -1;
}
