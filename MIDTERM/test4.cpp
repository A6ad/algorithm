#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
 int dx[] = {0, 0, 1, -1};
 int dy[] = {1, -1, 0, 0};
void bfs(vector<vector<char>>& maze,int sx,int sy,int ex,int ey,int n,int m) {
    queue<pair<int, int>> q;
    q.push({sx,sy});

    vector<vector<pair<int,int>>>par(n,vector<pair<int,int>>(m,{-1,-1}));
    par[sx][sy] = {sx,sy};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == ex && y == ey) {
            while (x != sx || y != sy) {
                if (maze[x][y] != 'R' && maze[x][y] != 'D') {
                    maze[x][y] = 'X';
                }
                auto p = par[x][y];
                x = p.first;
                y = p.second;
            }
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int move_x = x + dx[i];
            int move_y = y + dy[i];

            if (move_x >= 0 && move_x <n && move_y >= 0 && move_y < m && maze[move_x][move_y] != '#' && par[move_x][move_y].first == -1) {
                par[move_x][move_y] = {x, y};
                q.push({move_x,move_y});
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>>maze(n,vector<char>(m));

    int sx = -1,sy = -1;
    int ex = -1,ey = -1;

    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'R') {
                sx = i;
                sy = j;
            } else if (maze[i][j] == 'D') {
                ex = i;
                ey = j;
            }
        }
    }

    if (sx != -1 && sy != -1 && ex != -1 && ey != -1) {
        bfs(maze,sx,sy,ex,ey,n,m);
    }

    for (int i = 0;i<n;i++) {
        for (int j = 0;j<m;j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}