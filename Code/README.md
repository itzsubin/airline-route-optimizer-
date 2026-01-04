# ✈️ Airline Route Optimizer
A comprehensive C++ application that implements graph algorithms to solve complex airline routing problems. This project demonstrates advanced data structures and algorithm design for finding optimal flight paths, multi-city itineraries, and optimal meeting points.

## 🎯 Project Overview
This application solves three key airline routing problems using graph theory and efficient algorithms:

Direct Route Finding: Find the shortest path between two cities with connection limits

Multi-City Routing: Find optimal routes through intermediate cities

Optimal Meeting Points: Determine the best city for multiple people to meet minimizing total travel

## 🏗️ Data Structures & Algorithms

### Core Data Structures

-Graph: Implemented using unordered_map<string, unordered_set<string>> for O(1) neighbor lookups

-Adjacency List: Efficient storage of flight connections

-Queue: For BFS traversal

-Vectors: For path storage and intermediate city permutations

### Key Algorithms

-Breadth-First Search (BFS): For unweighted shortest path finding

-Permutation Generation: For multi-city route optimization

-Minimax Optimization: For optimal meeting point calculation

-Graph Traversal: Efficient path exploration

## 📁 Project Structure

airline-route-optimizer/
├── run.sh                          
├── data/
│   └── flight.txt                  # Flight route data
└── src/
    ├── main.cpp                    # Command-line interface
    ├── Graph.h                     # Graph class declaration
    ├── Graph.cpp                   # Graph algorithm implementations
    ├── FileParser.h                # File parsing interface
    ├── FileParser.cpp              # CSV flight data parser
    ├── RouteFinder.h               # Route finding interface
    ├── RouteFinder.cpp             # Route finding implementations
    └── utilis.h                    # Utility functions (trim, split, etc.)

## 🚀 Compilation & Execution
### Compile it with the provided script

#### Make the script executable
chmod +x run.sh

#### Run with question number and parameters
./run.sh 1 "New York" "London" 3
./run.sh 2 "New York" through "Chicago" and "Dallas" to "Houston"
./run.sh 3 "New York" "Chicago" "Los Angeles"

### Manual Compilation with G++

#### Create build directory
mkdir -p build
cd build

#### Compile with G++
g++ -std=c++17 -O2 -o routeSearch \
    ../src/main.cpp \
    ../src/Graph.cpp \
    ../src/RouteFinder.cpp \
    ../src/FileParser.cpp

#### Run the program
./routeSearch 1 "New York" "London" 3

### Manual Compilation with Clang++

#### Create build directory
mkdir -p build
cd build

#### Compile with Clang++
clang++ -std=c++17 -O2 -o routeSearch \
    ../src/main.cpp \
    ../src/Graph.cpp \
    ../src/RouteFinder.cpp \
    ../src/FileParser.cpp \
    ../src/Utilis.cpp

#### Run the program
./routeSearch 1 "New York" "London" 3

### Manual Compilation with G++

#### Create build directory
mkdir -p build
cd build

#### Compile with G++
g++ -std=c++17 -O2 -o routeSearch \
    ../src/main.cpp \
    ../src/Graph.cpp \
    ../src/RouteFinder.cpp \
    ../src/FileParser.cpp

#### Run the program
./routeSearch 1 "New York" "London" 3

## Question 1: Direct Route with Connection Limit

./run.sh 1 <start_city> <end_city> <max_connections>

##### Examples:
./run.sh 1 "New York" "London" 3
./run.sh 1 "Tokyo" "Seoul" 1
./run.sh 1 "Chicago" "Phoenix" 4

##### Output:
New York to London
Total connections: 1

## Question 2: 
./run.sh 2 <city_A> through <city_B> and <city_C> to <city_D>

##### Examples:
./run.sh 2 "New York" through "Chicago" and "Dallas" to "Houston"
./run.sh 2 "London" through "Paris" and "Rome" to "Athens"

##### Output:
London to Paris to Rome to Athens
Total connections: 3

## Question 3:
./run.sh 3 <city_A> <city_B> <city_C>

##### Examples:
./run.sh 3 "New York" "Chicago" "Los Angeles"
./run.sh 3 "London" "Paris" "Rome"

##### Output:
You three should meet at San Francisco
Route for first person: New York to Chicago to Denver to Phoenix to Los Angeles to San Francisco
Total connections: 5
Route for second person: Chicago to Denver to Phoenix to Los Angeles to San Francisco
Total connections: 4
Route for third person: Los Angeles to San Francisco
Total connections: 1
Total number of connections: 10

## 📝 Dependencies

C++17 or higher
Standard Library: <unordered_map>, <unordered_set>, <queue>, <vector>, <algorithm>
Compilers: G++ 7+, Clang++ 5+, or any C++17 compatible compiler


## 🎓 Academic Context

This project demonstrates:
-Graph Theory applications in real-world problems
-Algorithm Design and complexity analysis
-Data Structure selection and implementation
-Software Engineering best practices
-Problem Solving with computational thinking
