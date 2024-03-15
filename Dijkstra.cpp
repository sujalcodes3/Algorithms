#include<bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
using namespace std;

int main() {
    unordered_map<int, vector<pair<int, int>>> graph; // node -> {neigh, cost/distance}
    
    int N = 3;
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 6});
    graph[1].push_back({0, 1});
    graph[1].push_back({2, 3});
    graph[2].push_back({0, 6});
    graph[2].push_back({1, 3});

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int source = 2;

    vector<int> dijkstraDistances(N, INT_MAX);

    dijkstraDistances[source] = 0;

    pq.push({0, source});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto neigh : graph[node]) {
            int neighbour = neigh.first;
            int d = neigh.second;

            if(dijkstraDistances[neighbour] > d + cost) {
                dijkstraDistances[neighbour] = d + cost;
                pq.push({d + cost, neighbour});
            }
        }
    }
    

    for(int ele : dijkstraDistances) {
        cout << ele << " " ;
    }

    cout << endl;

    return 0;
}
