#include <bits/stdc++.h>
using namespace std;

int dis[1005]; 
bool cycle = false; 

class edge {
public:
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<edge> edge_list; 
int n, e; 

void bellman(int s) {
 
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;


    for (int i = 0; i < n - 1; i++) {
        for (auto& ed : edge_list) {
            if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b]) {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }

    for (auto& ed : edge_list) {
        if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b]) {
            cycle = true;
            break; 
        }
    }
}

int main() {
    cin >> n >> e;

 
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(edge(a, b, c));
    }

    int s; 
    cin >> s;

    int t; 
    cin >> t;

    
    bellman(s);

    
    if (cycle) {
        cout << "Negative Cycle Detected\n";
        return 0;
    }

  
    while (t--) {
        int d; 
        cin >> d;
        if (dis[d] == INT_MAX) {
            cout << "Not Possible\n";
        } else {
            cout << dis[d] << endl;
        }
    }

    return 0;
}