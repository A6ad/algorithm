#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj_list[105];
int dis[105];

void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dis[src] = 0;
    while(!q.empty())
    {
        
        pair<int,int> par = q.front();
        q.pop();

        int par_node= par.first;
        int par_dis = par.second;
       
        for(auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            if(par_dis+child_dis<dis[child_node])
         {
            dis[child_node] = par_dis + child_dis;
            q.push({child_node,dis[child_node]});
            
         }
        }
    }
}


int main() {
    int n,e;
    cin>>n>>e;
   
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj_list[a].push_back({b,c});
        adj_list[b].push_back({a,c});
    }
  for(int i=0;i<n;i++)
  {
    dis[i] = INT_MAX;
  }
dijkstra(0);

for(int i=0;i<n;i++)
{
    cout<<i<<"->"<<dis[i]<<endl;
}
}

// input
// 5 8
// 0 1 10
// 1 2 1
// 0 2 7
// 0 3 4
// 2 3 1
// 3 4 5
// 1 4 3
// 2 4 5

// output
// 0->0
// 1->6
// 2->5
// 3->4
// 4->9