#include <bits/stdc++.h>
#include <climits>
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

    set<pair<int, int>> st;

    int source = 2;

    st.insert({0, source});

    vector<int> dijkstraDistances(N, INT_MAX);

    dijkstraDistances[source] = 0;

    while(!st.empty()) {
        auto it = *st.begin();

        int tillCost = it.first;
        int node = it.second;

        st.erase(it);

        for(auto neigh : graph[node]) {
            int weight = neigh.second;
            int neighbour = neigh.first;

            if (tillCost + weight < dijkstraDistances[neighbour]) {
                if (dijkstraDistances[neighbour] != INT_MAX) {
                    st.erase({dijkstraDistances[neighbour], neighbour});
                }

                st.insert({tillCost + weight, neighbour});

                dijkstraDistances[neighbour] = tillCost + weight;
            }
        }
    }


    for (int ele : dijkstraDistances) {
        cout << ele << " "; 
    }

    cout << endl;

    return 0;
}
