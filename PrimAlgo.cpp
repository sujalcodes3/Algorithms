#include <iostream>
#include <queue>
#include<vector>
using namespace std;

typedef pair<int, int> P;


int main() {
    int V = 7;
    vector<vector<P>> graph(V);
    
    graph[0] = {{1, 5}, {3, 20}};
    graph[1] = {{2, 1}};
    graph[2] = {{3, 5}};
    graph[3] = {{0, 20}, {4, 1}};
    graph[4] = {{3, 1}, {5, 2}};
    graph[5] = {{4, 2}, {6, 2}};
    graph[6] = {{4, 4}, {5, 2}};

    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, 0});

    int sum = 0;

    vector<bool> inMST(V, false);

    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        
        pq.pop();
        
        if(inMST[node]) {
            continue;
        } 

        inMST[node] = true;
        sum += wt;

        for(auto & edge : graph[node]) {
            int neigh = edge.first;
            int wgt = edge.second;

            if(!inMST[neigh]) {
                pq.push({wgt, neigh});
            }
        } 
    }
    

    cout << sum << endl;
    return 0;
}
