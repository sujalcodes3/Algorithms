#include <vector>
#include <iostream>
using namespace std;

class UnionFind {
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n);
            for(int i = 0; i < n; i++) parent[i] = i;
        }
        
        int Find(int x) {
            if(parent[x] != x) {
                parent[x] = Find(parent[x]);
            }
            return parent[x];
        }

        void Union(int x, int y) {
            int x_ = Find(x);
            int y_ = Find(y);
            
            if(x_ == y_) return;

            if(rank[x_] > rank[y_]) {
                parent[y_] = x_;
            } else if (rank[y_] > rank[x_]) {
                parent[x_] = y_;
            } else {
                parent[y_] = x_;
                rank[x_] ++;
            }
        }

        bool connected(int x, int y) {
            return Find(x) == Find(y);
        }

        void reset(int x) {
            parent[x] = x;
            rank[x] = 0;
        }
};

int main() {

    cout << "See the code file to understand the implementation of DSU.";
    return 0;
}
