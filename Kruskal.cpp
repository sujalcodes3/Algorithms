#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef std::vector<int> vec;

vec parent;
vec rank;
    
int Find(int u) {
    if(u == parent[u]) {
        return u;
    }

    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);

    if(pu == pv) {
        return;
    }

    if(rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if(rank[pu] < rank[pv]) {
        parent[pv] = pu;
    } else {
        rank[pu] ++;
        parent[pv] = pu;
    }
}

int Kruskal(std::vector<vec> & adj, int V) {
    int sum = 0;
    
    for(int i = 0; i < V; i++) {
        parent[i] = i;
    }

    for(auto & edge : adj) {
        int u = edge[0]; 
        int v = edge[1]; 
        int wgt = edge[2]; 

        int pu = Find(u);
        int pv = Find(v);

        if(pu != pv){
            Union(u, v);
            sum += wgt;
        }
    }

    return sum; 
}

int main() {
    std::cout << "Kruskal's Algorithm\n";    
    
    std::vector<vec> adj;
    adj.push_back({0, 1, 5});
    adj.push_back({0, 3, 20});
    adj.push_back({1, 2, 1});
    adj.push_back({2, 3, 5});
    adj.push_back({3, 4, 1});
    adj.push_back({4, 5, 2});
    adj.push_back({4, 6, 4});
    adj.push_back({5, 6, 2});
    

    int V = 7;

    parent.resize(V);
    rank.resize(V, 0);
    
    sort(adj.begin(), adj.end(), [](vec & a, vec & b) {
        return a[2] < b[2];
    });

    
    std::cout << Kruskal(adj, V);

    printf("\n");
    return 0;
}
