#include "split.h"

std::vector<std::string>
split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    std::string::size_type beginIdx, endIdx;
    beginIdx = str.find_first_not_of(delim);

    while (beginIdx != std::string::npos)
    {
        endIdx = str.find_first_of(delim, beginIdx);
        tokens.push_back(str.substr(beginIdx, endIdx - beginIdx));
        beginIdx = str.find_first_not_of(delim, endIdx);
    }
    return tokens;
}
