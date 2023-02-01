/*
    PalindromeR.cpp

    Implementation file for the PalindromeR class

    For the recursive solution have test_string return -1 for a palindrome, 1 otherwise. Do not bother
    trying to count the number of matches. Implement the recursive test as follows:
*/

#include "PalindromeR.hpp"
#include <algorithm>
#include <string>

int PalindromeR::test_string(std::string s)
{
    // for efficiency purposes, we don't need to format the string more than once
    bool static firstTime = true;

    // only execute one time per string, firstTime is reset at the function return
    if (firstTime)
    {
        // remove capital letters
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        // remove punctuation
        s.erase (std::remove_if (s.begin (), s.end (), ispunct), s.end ());
        // remove spaces
        s.erase(std::remove_if(s.begin(), s.end(), isspace), s.end());
        firstTime = false;
    }

    // Strings of length 1 or less are palindromes
    if (s.length() <= 1)
    {
        // reset for next string
        firstTime = true;

        // -1 == s is a palindrome
        return -1;
    }

    // For larger strings, if the first and last characters agree, strip these two characters from the string
    // and test the remaining characters.
    else if (s[0] == s[s.length() - 1])
    {
        return test_string(s.substr(1, s.length() - 2));
    }

    // reset for next string
    firstTime = true;

    // 1 == s is NOT a palindrome
    return 1;
}
