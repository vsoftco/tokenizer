#include <stdexcept>
#include "token.h"

// tokenizer, standard C++98
std::vector<std::string> 
split(const std::string& str, const std::string& delim) 
{
    std::vector<std::string> result;
    if (str.empty()) // input string is empty
        // returns an empty vector<string>, useful when reading files
        return result; 
    std::string::const_iterator begin, str_it;
    begin = str_it = str.begin(); 
    do {
        // find the position of the first delimiter in str
        while (delim.find(*str_it) == std::string::npos && 
            str_it != str.end())
            str_it++;
        std::string token = std::string(begin, str_it); // grab the token
        if (!token.empty()) //  empty only when str starts with a delimiter
            result.push_back(token); // push the token
        // ignore the additional consecutive delimiters
        while (delim.find(*str_it) != std::string::npos && 
            str_it != str.end())
            str_it++;
        begin = str_it; // process the remaining tokens
    } while (str_it != str.end());
    return result;
}
