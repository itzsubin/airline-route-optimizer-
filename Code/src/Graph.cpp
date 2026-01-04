#include "Graph.h"
#include<algorithm>
#include<limits>
#include<queue>
using namespace std;

void Graph::addEdge(const string& from, const string& to) {
     adjacencyList[from].insert(to);
     adjacencyList[to];
}
void Graph::addVertex(const string&city){
     adjacencyList[city];
}

const unordered_set<string>& Graph::getNeighbors(const string& city) const{
     static const unordered_set<string> emptySet;
     auto it = adjacencyList.find(city);
     if(it!=adjacencyList.end()){
          return it->second;
     }
     else{
          return emptySet;
     }
}

bool Graph::containsCity (const string& city) const {
    return adjacencyList.find(city) != adjacencyList.end();
}

vector<string> Graph::getAllCities() const {
     vector<string> cities;
     for (const auto& pair : adjacencyList){
          cities.push_back(pair.first);
     }
     return cities;
}
void Graph::printGraph() const {
     for (const auto& pair : adjacencyList) {
          cout << pair.first << ": ";
          for (const auto& neighbor : pair.second) {
               cout << neighbor << " ";
          }
          cout << endl;
     }
}

PathResult Graph::shortestPath(const string& start, const string& end) const {
     PathResult result;
     if (!containsCity(start) || !containsCity(end)) return result;
     
     if (start == end) {
         result.path = {start};
         result.connections = 0;
         result.found = true;
         return result;
     }

     unordered_map<string, string> previous;
     unordered_map<string, bool> visited;
     queue<string> q;
     
     q.push(start);
     visited[start] = true;
     previous[start] = "";
     
     while (!q.empty()) {
          string current = q.front();
          q.pop();
          
          if (current == end) {
               vector<string> path;
               string node = end;
               while (!node.empty()) {
                    path.push_back(node);
                    node = previous[node];
               }
               reverse(path.begin(), path.end());
               
               result.path = path;
               result.connections = path.size() - 1;
               result.found = true;
               return result;
          }
          
          for (const string& neighbor : getNeighbors(current)) {
               if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    previous[neighbor] = current;
                    q.push(neighbor);
               }
          }
     }
     
     return result;
}

PathResult Graph::shortestPathWithConnections(const string& start, const string& end, int maxConnections) const {
     PathResult result = shortestPath(start, end);
     if (result.found && result.connections <= maxConnections) return result;
     
     result.found = false;
     result.connections = -1;
     result.path.clear();
     return result;
}

PathResult Graph::shortestPathThroughCities(const string& start, vector<string> &intermediate, const string& end) const {
     PathResult finalResult;
     finalResult.connections = INT_MAX;
     
     if (!containsCity(start) || !containsCity(end)) return finalResult;
     for (const string& city : intermediate) {
         if (!containsCity(city)) return finalResult;
     }
     
     vector<string> tempIntermediate = intermediate;
     sort(tempIntermediate.begin(), tempIntermediate.end());
     
     do {
          vector<string> fullPath;
          int totalConnections = 0;
          bool pathValid = true;
          
          PathResult segment1 = shortestPath(start, tempIntermediate[0]);
          if (!segment1.found) continue;
          fullPath = segment1.path;
          totalConnections += segment1.connections;
          
          for (size_t i = 0; i < tempIntermediate.size() - 1; i++) {
               PathResult segment = shortestPath(tempIntermediate[i], tempIntermediate[i+1]);
               if (!segment.found) {
                    pathValid = false;
                    break;
               }
               fullPath.insert(fullPath.end(), segment.path.begin() + 1, segment.path.end());
               totalConnections += segment.connections;
          }
          if (!pathValid) continue;
          
          PathResult segment2 = shortestPath(tempIntermediate.back(), end);
          if (!segment2.found) continue;
          fullPath.insert(fullPath.end(), segment2.path.begin() + 1, segment2.path.end());
          totalConnections += segment2.connections;
          
          if (totalConnections < finalResult.connections) {
               finalResult.path = fullPath;
               finalResult.connections = totalConnections;
               finalResult.found = true;
          }
          
     } while (next_permutation(tempIntermediate.begin(), tempIntermediate.end()));
     
     return finalResult;
}

unordered_map<string, int> Graph::bfsAllDistances(const string& start) const {
     unordered_map<string, int> distances;
     if (!containsCity(start)) return distances;
     
     queue<string> q;
     q.push(start);
     distances[start] = 0;
     
     while (!q.empty()) {
          string current = q.front();
          q.pop();
          
          for (const string& neighbor : getNeighbors(current)) {
               if (distances.find(neighbor) == distances.end()) {
                    distances[neighbor] = distances[current] + 1;
                    q.push(neighbor);
               }
          }
     }
     
     return distances;
}

PathResult Graph::optimizeMeetingPoint(const vector<string> &cities) const {
     PathResult result;
     
     for (const string& city : cities) {
         if (!containsCity(city)) return result;
     }
     
     vector<string> allCities = getAllCities();
     vector<string> candidateCities;
     for (const string& city : allCities) {
         if (find(cities.begin(), cities.end(), city) == cities.end()) {
             candidateCities.push_back(city);
         }
     }
     
     if (candidateCities.empty()) return result;
     
     vector<unordered_map<string, int>> allDistances;
     for (const string& city : cities) {
         allDistances.push_back(bfsAllDistances(city));
     }
     
     string bestCity;
     int minMaxDistance = INT_MAX;
     int minTotalDistance = INT_MAX;
     
     for (const string& candidate : candidateCities) {
          bool reachable = true;
          int maxDistance = 0;
          int totalDistance = 0;
          
          for (const auto& distanceMap : allDistances) {
               if (distanceMap.find(candidate) == distanceMap.end()) {
                    reachable = false;
                    break;
               }
               int dist = distanceMap.at(candidate);
               maxDistance = max(maxDistance, dist);
               totalDistance += dist;
          }
          
          if (reachable) {
               if (maxDistance < minMaxDistance || 
                   (maxDistance == minMaxDistance && totalDistance < minTotalDistance)) {
                    minMaxDistance = maxDistance;
                    minTotalDistance = totalDistance;
                    bestCity = candidate;
               }
          }
     }
     
     if (minMaxDistance == INT_MAX) return result;
     
     result.found = true;
     result.connections = minTotalDistance;
     result.path = {bestCity};
     return result;
}


