#pragma once
#include "Graph.h"
#include <string>
using namespace std;

class FileParser {
public:
    Graph parseFile(const string& filename);
};