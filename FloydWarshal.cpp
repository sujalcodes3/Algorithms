#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printMatrix(vector<vector<long>> & matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    cout << endl;

    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++){
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

vector<vector<long>> floydWarshal(int n, int m, vector<vector<int>> & edges) {
    vector<vector<long>> pairDistances(n, vector<long> (n, INT_MAX));

    for(auto &edge : edges) {
        int from = edge[0];
        int to = edge[1];
        int weight = edge[2];

        pairDistances[from][to] = weight;
    }
    
    for(int i = 0; i < n; i++) {
        pairDistances[i][i] = 0;
    }
    printMatrix(pairDistances);

    for(int via = 0; via < n; via ++) { // for the via logic

        // the next loops are for traversing each valid edge.
        for(int from = 0; from < n; from ++) {
            for(int to = 0; to < n; to ++) {

                if(to != from) {
                    pairDistances[from][to] = min(pairDistances[from][to], pairDistances[from][via] + pairDistances[via][to]);
                    cout << from << " " << via << " " << to << endl;
                    printMatrix(pairDistances);
                }
            }
        }
    }      
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(pairDistances[i][j] >= INT_MAX) {
                pairDistances[i][j] = -1;
            }
        }
    }

    return pairDistances;
}

int main() {
    vector<vector<int>> edges;
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int from, to, weight;

        cin >> from >> to >> weight;

        edges.push_back({from, to, weight});
    }
    

    vector<vector<long>> leastDistances = floydWarshal(n, m, edges);

    printMatrix(leastDistances);

    return 0;
}
