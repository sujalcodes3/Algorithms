#include <iostream>

#include <climits>
#include <vector>

using namespace std;

void BellmanFord(int N, int M, int src, vector<vector<int>> & edges) {
    vector<int> distances(N + 1, INT_MAX); // 1 Indexed graph
    distances[src] = 0;

    for(int iteration = 1; iteration <= M - 1; iteration ++) {
        cout << "Iteration " << iteration << ": \n";

        for(auto &edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight= edge[2];

            if(distances[from] != INT_MAX && distances[from] + weight < distances[to]) {
                distances[to] = distances[from] + weight;
                cout << "RELAX: " << to << " -> value = " << distances[to] << endl;
            }
        }

        cout<< endl;
    }

    for(auto &edge : edges) {
        int from = edge[0];
        int to = edge[1];
        int weight= edge[2];

        if(distances[from] != INT_MAX && distances[from] + weight < distances[to]) {
            cout << "Negative Cycle found... STOP"; 
            cout <<  -1 << endl;
            return ;
        }
    }

    for(int distance : distances) {
        cout << distance << " ";
    }
    cout << endl;
}

int main() {

    int N = 4;
    int M = 4;
    int src = 1;

    vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}};

    BellmanFord(N, M, src, edges);
    return 0;
}
