#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include "token.h"

template<typename T>
void displayContainer(const T &container)
{
    for (typename T::const_iterator it = container.begin();
            it != container.end(); it++)
        std::cout << "[" << *it << "]" << " ";
}

void displayTextFile(const std::string& fname)
{
	std::ifstream fin(fname.c_str());
	if(!fin)
		throw std::runtime_error("Cannot open input file \"" + fname + "\"");
	std::cout << fin.rdbuf();
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Need 2 arguments: \"filename\" and \"delimiters\""\
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    std::ifstream fin(argv[1]); // input file stream
    if (!fin)
        throw std::runtime_error("Cannot open input file \""\
			   + std::string(argv[1]) + "\"");

    std::string delim(argv[2]); // delimiter

    std::cout << "The original file is: " << std::endl;
    displayTextFile(argv[1]);

    std::cout << std::endl << "The tokenized file is: " << std::endl;
    std::string tmp;
    while (std::getline(fin, tmp)) // tokenize each line
    {
        displayContainer(split(tmp, delim));
        std::cout << std::endl;
    }

    return 0;
}
