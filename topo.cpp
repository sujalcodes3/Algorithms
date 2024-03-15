#include <bits/stdc++.h>
using namespace std;

#define ll

void DFS(int node, vector<bool> &vis, stack<int> &st,
         unordered_map<int, vector<int>> &graph) {
  vis[node] = true;

  for (int neighbor : graph[node]) {
    if (!vis[neighbor]) {
      DFS(neighbor, vis, st, graph);
    }
  }

  st.push(node);
}

void BFS(unordered_map<int, vector<int>> &graph, vector<int> &indegree,
         queue<int> &q, vector<int> &ans) {
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    ans.push_back(node);

    for (int neigh : graph[node]) {
      if (--indegree[neigh] == 0) {
        q.push(neigh);
      }
    }
  }
}

int main() {
  unordered_map<int, vector<int>> graph;

  int V = 6;

  graph[0] = {2, 3};
  graph[1] = {4};
  graph[2] = {1, 3};
  graph[3] = {1};
  graph[4] = {};
  graph[5] = {1, 4};

  // for Kahn's Algorithm
  vector<int> indegree(V, 0);

  for (int i = 0; i < V; i++) {
    for (int &neigh : graph[i]) {
      indegree[neigh]++;
    }
  }
  queue<int> q;

  for (int i = 0; i < V; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> ans;

  BFS(graph, indegree, q, ans);

  for (int ele : ans) {
    cout << ele << " ";
  }
  cout << endl;
  /*
   // for DFS
   stack<int> st;
    vector<bool> vis(V, false);

    for(int i = 0; i < V; i++) {
    if(!vis[i]) {
    DFS(i, vis, st, graph);
    }
    }

  // printing piece of code.
  cout << "Topological Sort : " ;
  while(!st.empty()) {
  cout << st.top() << " ";
  st.pop();
  }
  cout << endl;
  */

  return 0;
}
