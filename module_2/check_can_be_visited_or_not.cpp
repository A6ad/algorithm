#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty())
    {   
        //ber kore ana
        int par = q.front();
        q.pop();

        // oi node niye
        

        // child push kora
        for(int child : adj_list[par])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true ;
            }
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
    memset(vis,false,sizeof(vis)); 
   
    int src,dst;
    cin>>src>>dst;
    bfs(src);


    if(vis[dst])
    {
        cout<<"Yes\n";
    }
    else 
    {
        cout<<"NO\n";
    }
    return 0;
}
