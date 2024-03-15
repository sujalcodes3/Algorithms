#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void DFS(unordered_map<int, vector<int>> & adj, int node, vector<bool> & visited) {
    visited[node] = true;
    
    for(int neigh : adj[node]) {
        if(!visited[neigh]) {
            DFS(adj, neigh, visited);
        }
    }
}

bool isConnected(int V, unordered_map<int, vector<int>> & adj) {
    int nonZeroDegreeVertex = -1;

    for(int i = 0; i < V; i++) {
        if(adj[i].size() > 0) {
            nonZeroDegreeVertex= i;
            break;
        }
    }

    // start dfs
    vector<bool> visited(V, false);
    DFS(adj, nonZeroDegreeVertex, visited);
    
    // start checking if all vertices with non zero indegree are visited
    for(int i = 0; i < V; i++) {
        if(adj[i].size() && !visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main(){
    unordered_map<int, vector<int>> adj;
    int V;
    if(isConnected(V, adj) == false) {
        cout << "NONE" << endl;
        return 0;
    }
    int oddDegreeCount = 0;

    for(int i = 0; i < V; i++) {
        if(adj[i].size() % 2) {
            oddDegreeCount ++;
        }
    }
    
    if(oddDegreeCount > 2) {
        cout << "NONE" << endl;
        return 0; 
    }
    if(oddDegreeCount == 2){
        cout << "Euler Path" << endl;
        return 0;
    }

    if(oddDegreeCount == 0) {
        cout << "Euler Circuit" << endl;
        return 0;
    }

    cout << endl;
    return 0;
}
