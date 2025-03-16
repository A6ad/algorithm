#include <bits/stdc++.h>
using namespace std;
int INF = INT_MAX;
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj_mat(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        adj_mat[i][i] = 0;
    }
    while (e--) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--; 
        if (adj_mat[a][b] > c) {
            adj_mat[a][b] = c;
        }
    }

   
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj_mat[i][k] != INF && adj_mat[k][j] != INF && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j]) {
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--; 

        
        if (x < 0 || x >= n || y < 0 || y >= n) {
            cout << -1 << endl;
            continue;
        }

        if (adj_mat[x][y] == INF) {
            cout << -1 << endl;
        } else {
            cout << adj_mat[x][y] << endl;
        }
    }

    return 0;
}