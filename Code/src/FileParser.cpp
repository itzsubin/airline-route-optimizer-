#include "FileParser.h"
#include "utilis.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Graph FileParser::parseFile(const string&filename){
     Graph graph;
     ifstream file(filename);
     string line;

     if (!file.is_open()) {
          cerr << "Error: Could not open file " << filename <<endl;
          return graph;
    }

    while (getline(file, line)){
     stringstream ss(line); // read one by one (words)
     string fromCity, toCity, distance;
    

    if(getline(ss, fromCity, ',') &&
          getline(ss,toCity, ',') &&
          getline(ss, distance, ',')){

               fromCity = utilis::trim(fromCity);
               toCity = utilis::trim(toCity);

               graph.addEdge(fromCity, toCity); //remove the distance not needed
     }
}
file.close();
 
return graph;
}



