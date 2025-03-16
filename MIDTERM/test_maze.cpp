#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int dx[] = {0, 0, 1, -1}; // Right, Left, Down, Up
const int dy[] = {1, -1, 0, 0};

void bfs(vector<vector<char>>& maze, int startX, int startY, int exitX, int exitY, int N, int M) {
    queue<pair<int, int>> q;
    q.push({startX, startY});

    vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(M, {-1, -1}));
    parent[startX][startY] = {startX, startY};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;

        if (x == exitX && y == exitY) {
            // Reconstruct path
            while (x != startX || y != startY) {
                maze[x][y] = 'X';
                auto p = parent[x][y];
                x = p.first;
                y = p.second;
            }
            maze[startX][startY] = 'X';
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && parent[nx][ny].first == -1) {
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> maze(N, vector<char>(M));

    int startX = -1, startY = -1;
    int exitX = -1, exitY = -1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'R') {
                startX = i;
                startY = j;
            } else if (maze[i][j] == 'D') {
                exitX = i;
                exitY = j;
            }
        }
    }

    if (startX != -1 && startY != -1 && exitX != -1 && exitY != -1) {
        bfs(maze, startX, startY, exitX, exitY, N, M);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << maze[i][j];
        }
        cout << endl;
    }

    return 0;
}