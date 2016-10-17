#include <iostream>
#include <string>
#include "split.h"

template<typename T>
void disp(const T& container)
{
    std::cout << "[";
    bool first = true;
    for (typename T::const_iterator it = container.begin();
            it != container.end(); ++it)
    {
        if(first)
        {
            std::cout << *it;
            first = false;
        }
        else
        {
            std::cout << " " << *it;
        }
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::string str1 = "This is a test";
    disp(split(str1));        // by default splits on white spaces
    std::string str2 = "This,is:some:other;test";
    disp(split(str2, ",:;")); // custom split delimiters
}
