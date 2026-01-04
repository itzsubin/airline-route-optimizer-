#pragma once
#include <string>
#include <vector>
using namespace std;

namespace utilis {
     vector<string> splitString(const string& str, char delimiter);
     string trim(const string& str);

     template<typename T>
     bool contains(const vector<T>& vec, const T& value) {
         for (const auto& item : vec) {
             if (item == value) return true;
         }
         return false;
     }
}