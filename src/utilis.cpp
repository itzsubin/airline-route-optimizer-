#include "utilis.h"
#include <algorithm>
#include <cctype>

using namespace utilis;

vector<string> utilis::splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != string::npos) {
        token = str.substr(start, end - start);
        token = trim(token);
        if (!token.empty()) tokens.push_back(token);
        start = end + 1;
        end = str.find(delimiter, start);
    }
    
    token = str.substr(start);
    token = trim(token);
    if (!token.empty()) tokens.push_back(token);
    
    return tokens;
}

string utilis::trim(const string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = str.find_last_not_of(" \t\n\r");
    return str.substr(start, end - start + 1);
}