#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<int> graph[], int N) {
    vector<int> indegree(N, 0);
    vector<int> res;

    queue<int> q;


    for(int i = 0; i < N; i++) {
        for(int & ele : graph[i]) {
            indegree[ele] ++;
        }
    }

    for(int i = 0; i < N; i ++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node;

        res.push_back(node);

        for(int neigh : graph[node]) {
            if(--indegree[neigh] == 0) {
                q.push(neigh);
            }
        }
    }

    return res;
}

string getAlienLanguage(vector<string> &dictionary, int k) {
    int n = dictionary.size();

    vector<int> graph[k];
    for(int i = 0; i < n - 1; i ++) {
        string currStr = dictionary[i];
        string nextStr = dictionary[i + 1];

        int len = min(currStr.size(), nextStr.size());

        for(int t = 0; t < len; t ++) {
            if(currStr[t] != nextStr[t]) {
                graph[currStr[t] - 'a'].push_back(nextStr[t] - 'a');
                break;
            }
        }
    }

    vector<int> orderTopo = topoSort(graph, k);

    string order = "";

    for(int ele : orderTopo) {
        order += char(ele + 'a') ;
    }

    return order;
}

int main() {
    
    int n, k;
    cin >> n >> k;

    vector<string> dictionary;

    for(int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }

    string ans = getAlienLanguage(dictionary, k);
   
    cout << ans;

        
    return 0;
}
