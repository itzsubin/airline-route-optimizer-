#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct PathResult {
     vector<string> path;
     int connections;
     bool found;
     PathResult() : connections(-1), found(false) {}
};

class Graph{
     private:
          unordered_map<string, unordered_set<string>> adjacencyList;

     public:
          void addEdge(const string& from, const string& to);
          void addVertex(const string& city);
          const unordered_set<string>& getNeighbors(const string& city) const;
          bool containsCity(const string& city) const;
          vector<string> getAllCities() const;
          void printGraph() const;

          // Shortest path 
          PathResult shortestPath(const string& start, const string& end) const;
          PathResult shortestPathWithConnections(const string& start, const string& end, int maxConnections) const;

          // MultiCity path finding
          PathResult shortestPathThroughCities(const string& start, vector<string> &intermediate, const string& end) const;

          // Meeting Point
          unordered_map<string, int> bfsAllDistances(const string& start) const;
          PathResult optimizeMeetingPoint(const vector<string> &cities) const;
};

