#include <bits/stdc++.h>
using namespace std;

int knight_min_steps(int N, int M, int K1, int K2, int Q1, int Q2) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, int>> q;
    queue<int> steps;

    // 8 possible moves of a knight
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    // Start BFS from the knight's position
    q.push({K1, K2});
    steps.push(0);
    visited[K1][K2] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int step = steps.front();
        q.pop();
        steps.pop();

        // If we reach the queen's position, return steps taken
        if (x == Q1 && y == Q2)
            return step;

        // Try all 8 possible moves
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                steps.push(step + 1);
            }
        }
    }

    // If no path found
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M, K1, K2, Q1, Q2;
        cin >> N >> M;
        cin >> K1 >> K2;
        cin >> Q1 >> Q2;

        cout << knight_min_steps(N, M, K1, K2, Q1, Q2) << endl;
    }

    return 0;
}
