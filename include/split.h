#ifndef SPLIT_H_
#define SPLIT_H_

#include <vector>
#include <string>

// tokenizer, standard C++98
// white spaces as default delimiter
std::vector<std::string> 
split(const std::string& str, const std::string& delim = " \t\n"); 

#endif // SPLIT_H_
