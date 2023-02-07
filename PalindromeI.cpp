/*
    PalindromeI.cpp

    Implementation file for the PalindromeI class
*/

#include "Queue.hpp"
#include "Stack.hpp"
#include "PalindromeI.hpp"
#include <string>
#include <algorithm>

/*
    Test to see if a string is a palindrome via iteration

    @param[in, out] c++ string
    @return integer representing whether or not s is a palindrome
    @retval -1 palindrome
    @retval !=-1 not a palindrome
*/
int PalindromeI::test_string(std::string s)
{
    // remove all ignored characters:

    // remove capital letters
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    // remove punctuation
    s.erase (std::remove_if (s.begin (), s.end (), ispunct), s.end ());
    // remove spaces
    s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());

    // declare a queue and a stack
    Queue<char> queue(s.length());
    Stack<char> stack;

    // the number of correct matches before mismatch
    int numOfMatches = 0;

    // add all of the characters to the stack and queue, front to back
    for (char c:s)
    {
        queue.enqueue(c);
        stack.push(c);
    }

    // while the stack and queue are both not empty
    while (!stack.isEmpty() && !queue.isEmpty())
    {
        // check to see if the next letter from each is the same
        if (stack.pop() != queue.dequeue())
        {
            // if the characters are not equal...

            // destroy the stack and queue appropriately
            stack.~Stack();
            queue.~Queue();

            // return the number of correct matches before the mismatch occurred.
            return numOfMatches;
        }

        // if they are equal, increment a counter for the correct number of matches.
        else
        {
            numOfMatches++;
        }
    }

    // when both the stack and queue are empty, return -1 to indicate it is a palindrome.
    return -1;
}
