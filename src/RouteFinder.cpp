#include "RouteFinder.h"

RouteFinder::RouteFinder(const Graph& graph) : graph(graph) {}

PathResult RouteFinder::findRouteWithMaxConnections(const string& start, const string& end, int maxConnections) {
    return graph.shortestPathWithConnections(start, end, maxConnections);
}

PathResult RouteFinder::findRouteThroughCities(const string& start, const vector<string>& intermediate, const string& end) {
    std::vector<string> temp = intermediate;
    return graph.shortestPathThroughCities(start, temp, end);
}

PathResult RouteFinder::findOptimalMeetingPoint(const vector<string>& cities) {
    return graph.optimizeMeetingPoint(cities);
}