#include "Graph.h"
#include "FileParser.h"
#include "RouteFinder.h"
#include "utilis.h"
#include <iostream>
#include <vector>

using namespace std;

void printUsage() {
    cout << "Usage:" << endl;
    cout << "  routeSearch 1 <city_A> <city_B> <num_connection>" << endl;
    cout << "  routeSearch 2 <city_A> through <city_B> and <city_C> to <city_D>" << endl;
    cout << "  routeSearch 3 <city_A> <city_B> <city_C>" << endl;
}

void printPath(const PathResult& result) {
    if (!result.found) {
        cout << "No route found" << endl;
        return;
    }
    
    for (size_t i = 0; i < result.path.size(); i++) {
        cout << result.path[i];
        if (i < result.path.size() - 1) cout << " to ";
    }
    cout << endl;
    cout << "Total connections: " << result.connections << endl;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage();
        return 1;
    }
    
    FileParser parser;
    Graph graph = parser.parseFile("../data/flight.txt");
    RouteFinder finder(graph);
    
    int question = stoi(argv[1]);
    
    switch (question) {
        case 1: {
            if (argc != 5) {
                cout << "Usage: routeSearch 1 <city_A> <city_B> <num_connection>" << endl;
                return 1;
            }
            
            string cityA = argv[2];
            string cityB = argv[3];
            int maxConnections = stoi(argv[4]);
            
            PathResult result = finder.findRouteWithMaxConnections(cityA, cityB, maxConnections);
            
            if (result.found) {
                printPath(result);
            } else {
                cout << "No route found from " << cityA << " to " << cityB 
                     << " with " << maxConnections << " or fewer connections" << endl;
            }
            break;
        }
        
        case 2: {
            if (argc != 9) {
                cout << "Usage: routeSearch 2 <city_A> through <city_B> and <city_C> to <city_D>" << endl;
                return 1;
            }
            
            string cityA = argv[2];
            string cityB = argv[4];
            string cityC = argv[6];
            string cityD = argv[8];
            
            vector<string> intermediate = {cityB, cityC};
            PathResult result = finder.findRouteThroughCities(cityA, intermediate, cityD);
            
            if (result.found) {
                printPath(result);
            } else {
                cout << "No route found through the specified cities" << endl;
            }
            break;
        }
        
        case 3: {
            if (argc != 5) {
                cout << "Usage: routeSearch 3 <city_A> <city_B> <city_C>" << endl;
                return 1;
            }
            
            string cityA = argv[2];
            string cityB = argv[3];
            string cityC = argv[4];
            
            vector<string> cities = {cityA, cityB, cityC};
            PathResult result = finder.findOptimalMeetingPoint(cities);
            
            if (result.found) {
                string meetingCity = result.path[0];
                cout << "You three should meet at " << meetingCity << endl;
                
                vector<string> startingCities = {cityA, cityB, cityC};
                vector<string> personNames = {"first", "second", "third"};
                int totalConnections = 0;
                
                for (size_t i = 0; i < startingCities.size(); i++) {
                    PathResult route = graph.shortestPath(startingCities[i], meetingCity);
                    cout << "Route for " << personNames[i] << " person: ";
                    if (route.found) {
                        printPath(route);
                        totalConnections += route.connections;
                    } else {
                        cout << "No route found" << endl;
                    }
                }
                cout << "Total number of connections: " << totalConnections << endl;
                
            } else {
                cout << "No suitable meeting point found" << endl;
            }
            break;
        }
        
        default:
            printUsage();
            return 1;
    }
    
    return 0;
}