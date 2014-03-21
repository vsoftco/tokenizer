#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "token.h"


template<typename T> 
void displayContainer(const T& container)
{
    for(typename T::const_iterator it = container.begin(); 
        it != container.end(); it++)
        std::cout << *it << " ";    
}

void displayTextFile(const char* fname)
{
    std::string tmp;
    std::ifstream file(fname);
    while(std::getline(file,tmp))
        std::cout << tmp << std::endl;
}

int main(int argc, char *argv[]) 
{
    if(argc!=3)
    {
        std::cout << "Need 2 arguments: filename and delimiter" << std::endl;
        return 1;
    }    
    std::ifstream file(argv[1]); // input file stream
    std::string delim(argv[2]); // delimiter 

    std::cout << "The original file is: " << std::endl;
    displayTextFile(argv[1]);
    
    std::cout << std::endl << "The tokanized file is: " << std::endl;
    std::string tmp;
    while(std::getline(file, tmp)) // tokenize each line
    {
        displayContainer<std::vector<std::string> >(split(tmp, delim));
        std::cout << std::endl;
    }   
    
    return 0; 
}
