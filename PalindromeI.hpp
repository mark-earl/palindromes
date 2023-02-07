/*
    PalindromeI.hpp

    Interface file for the PalindromeI class
*/

#ifndef PALINDROMEI_HPP
#define PALINDROMEI_HPP

#include <string>

class PalindromeI
{
    public:
        PalindromeI() {}

        /*
            Test to see if a string is a palindrome via iteration

            @param[in, out] c++ string
            @return integer representing whether or not s is a palindrome
            @retval -1 palindrome
            @retval !=-1 not a palindrome
        */
        int test_string(std::string s);
};

#endif
