CC = g++
FLAGS = -std=c++11

all: palindrome.out clean

Stack.o: Stack.cpp
	    ${CC} ${FLAGS} -c Stack.cpp

Queue.o: Queue.cpp
	    ${CC} ${FLAGS} -c Queue.cpp

PalindromeI.o: PalindromeI.cpp
	    ${CC} ${FLAGS} -c PalindromeI.cpp

PalindromeR.o: PalindromeR.cpp
	    ${CC} ${FLAGS} -c PalindromeR.cpp

palindrome.out: Stack.o Queue.o PalindromeI.o PalindromeR.o test_palindrome.cpp
		${CC} ${FLAGS} test_palindrome.cpp *.o -o palindrome.out

clean:
	rm -f *.o
	rm -f *~
	rm -f \#*
