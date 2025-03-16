#include <bits/stdc++.h>
using namespace std;
int area_of_components(int n,int m,vector<vector<char>>& grid) {
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int min = INT_MAX;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                int area = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;

                while (!q.empty()) {
                    auto current = q.front();
                    q.pop();
                    int x = current.first;
                    int y = current.second;
                    ++area;

                    for (auto& d : dir) {
                        int nx = x + d[0];
                        int ny = y + d[1];

                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                if (area < min) {
                    min = area;
                }
            }
        }
    }

    if(min == INT_MAX)
    {
        return -1;
    }
    else 
    {
        return min;
    }
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int res = area_of_components(n,m,grid);
    cout<<res<<endl;
    
    return 0;
}