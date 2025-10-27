#include <iostream>
#include <string.h>
using namespace std;

void ReverseString(char *str, int size)
{
    char *forwardPtr = str;
    char *backwardPtr = str + size - 1;
    while (forwardPtr < backwardPtr)
    {
        char temp = *forwardPtr;
        *forwardPtr = *backwardPtr;
        *backwardPtr = temp;
        forwardPtr++;
        backwardPtr--;
    }
}

int main()
{
    char str[] = "hello world";
    ReverseString(str, strlen(str));
    cout << str << endl;
    return 0;
}