#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, vector<bool> & visited, stack<int> & s, vector<vector<int>> & adj) {
    visited[u] = true;

    for(int & neigh : adj[u]) {
        if(!visited[neigh]) {
            dfs(neigh, visited, s, adj);
        }
    }

    s.push(u);
}

void dfs2(int u, vector<vector<int>> & adj, vector<bool> & visited) {
    visited[u] = true;

    for(int & neigh : adj[u]) {
        if(!visited[u]) {
            dfs2(neigh, adj, visited);
        }
    }
}

void Kosaraju(vector<vector<int>> & revAdj, stack<int> & st, int V, vector<bool> & visited, int * cnt) {
    while(!st.empty()) {
        int u = st.top();
        st.pop();

        if(!visited[u]) {
            (*cnt) ++;
            dfs2(u, revAdj, visited);
        }
    } 
}

int main() {
    int V = 7;
    stack<int> st;

    vector<vector<int>> adj(V);

    vector<bool> visited(V, false);

    for(int i = 0; i < V; i ++) {
        if(!visited[i]) {
            dfs(i, visited, st, adj);
        }
    }

    vector<vector<int>> revAdj(V);
    
    for(int node = 0; node < V; node++) {
        for(int & neigh : adj[node]) {
            revAdj[neigh].push_back(node);
        }
        visited[node] = false;
    }
    
    int cnt = 0;
    Kosaraju(revAdj, st, V, visited, &cnt);

    cout << cnt;

    cout << endl;
    return 0;
}
