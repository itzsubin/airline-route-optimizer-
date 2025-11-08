#pragma once
#include "Graph.h"
#include <string>
#include <vector>
using namespace std;

class RouteFinder {
public:
    RouteFinder(const Graph& graph);
    
    PathResult findRouteWithMaxConnections(const string& start, const string& end, int maxConnections);
    PathResult findRouteThroughCities(const string& start, const vector<string>& intermediate, const string& end);
    PathResult findOptimalMeetingPoint(const vector<string>& cities);
    
private:
    Graph graph;
};