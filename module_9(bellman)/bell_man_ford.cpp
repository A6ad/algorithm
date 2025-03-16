// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3
#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int a, b, c;
    edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int dis[1005];
vector<edge> edge_list;
int n, e;
void bellman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {

        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[ed.a] != INT_MAX && dis[ed.a] + ed.c < dis[ed.b])
            {
                dis[ed.b] = dis[ed.a] + ed.c;
            }
        }
    }
}

int main()
{

    cin >> n >> e;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[0] = 0;
    bellman_ford();
    for (int i = 0; i < n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }

    return 0;
}