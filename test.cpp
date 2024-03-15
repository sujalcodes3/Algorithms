#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int row = 5, col = 5;
    int nRow, nCol;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j ++) {
            nRow = row + i; 
            nCol = col + j;
            cout << nRow << " " << nCol << endl;
        }

    }

    return 0;
}
