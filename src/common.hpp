#ifndef __Common__
#define __Common__

#include <algorithm>
#include <string>

const int WORDLENGTH = 5;
const int GUESSES = 6;

static std::string str_toupper(std::string& s){
    std::transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c){ return std::toupper(c); }
    );
    return s;
};

#endif /* __Common__ */