#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        //ber kore ana
        int par = q.front();
        q.pop();

        //oi node niye kaj
        cout<<par<<" ";

        //children push kora
        for(auto child : adj_list[par])
        {
            
        }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
   

    while(e--)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
        
    }
    bfs(0);
    return 0;
}