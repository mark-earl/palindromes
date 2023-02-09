/*
    PalindromeR.hpp

    Recursive palindrome tester, interface file for the PalindromeR class
*/

#ifndef PALINDROMER_HPP
#define PALINDROMER_HPP

#include <string>

class PalindromeR
{
    public:
        PalindromeR() {}

        /*
            Test to see if a string is a palindrome via recursion

            @param[in] c++ string
            @return integer representing whether or not s is a palindrome
            @retval -1 palindrome
            @retval 1 not a palindrome
        */
        int test_string(std::string s);
};

#endif
