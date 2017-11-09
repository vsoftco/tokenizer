#include <iostream>
#include <string>
#include "split.h"

template<typename T>
void disp(const T& container)
{
    for (typename T::const_iterator it = container.begin();
            it != container.end(); ++it)
    {
        std::cout << '[' << *it << "] ";
    }
}

int main()
{
    std::string str1 = "This is a test";
    std::cout << "Tokens: ";
    disp(split(str1));        // by default splits on white spaces
    std::cout << '\n';

    std::string str2 = "This, is:some:other;test";
    std::cout << "Tokens: ";
    disp(split(str2, " ,:;")); // custom split delimiters
    std::cout << '\n';
}
