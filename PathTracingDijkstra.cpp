#include <bits/stdc++.h>
#include <boost/range/adaptor/reversed.hpp>
using namespace std;

typedef pair<int, int> P;

int main() {
    unordered_map<int, vector<P>> graph;
    
    int N = 7;
    graph[0] = {{2, 6}, {1, 2}};
    graph[1] = {{0, 2}, {3, 5}};
    graph[2] = {{0, 6}, {3, 8}};
    graph[3] = {{2, 8}, {1, 5}, {4, 10}, {5, 15}};
    graph[4] = {{3, 10}, {6, 2}};
    graph[5] = {{3, 15}, {6, 6}};
    graph[6] = {{4, 2}, {5, 6}};

    priority_queue<P> pq;

    vector<int> minCostDistances(N, INT_MAX);
    
    int source = 0;
    int destination = 6;

    pq.push({0,source});
    minCostDistances[source] = 0;

    vector <int> parent(N, 0);
    for(int i = 0; i < N; i++) {
        parent[i] = i;
    }

    while(!pq.empty()) {
        int costTill = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(P neigh : graph[node]) {
            int neighbour = neigh.first;
            int weight = neigh.second;

            if(weight + costTill < minCostDistances[neighbour]) {
                minCostDistances[neighbour] = weight + costTill;
                parent[neighbour] = node;
                pq.push({weight + costTill, neighbour});
            }
        }
    }

    if(minCostDistances[destination] == INT_MAX) {
        cout << "No path to destination";
        return 0;
    }


    cout << "distances" << endl;

    for(int ele : minCostDistances) {
        cout << ele << " ";
    }
    cout <<endl <<  "parent" << endl;
    for(int ele : parent) {
        cout << ele << " ";
    }

    cout << endl;

    vector<int> revPath = {destination};
    while(parent[destination] != destination) {
        revPath.push_back(parent[destination]);
        destination = parent[destination];
    } 
    
    cout << "Shortest Path to Destination: " << endl;

    for(int ele : boost::adaptors::reverse(revPath)) { 
        cout << ele << "->";
    } 

    cout << "REACHED" << endl;

    return 0;
}
