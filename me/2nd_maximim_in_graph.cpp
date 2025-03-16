#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005]; // array of vector
bool vis[1005];


int max1 = INT_MIN;
int max2 = INT_MIN;

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

        //oi node niye kaj
        if(par>max1)
        {
            max2 = max1;
            max1 = par ;
        }
        else if(par>max2 && par != max1)
        {
            max2 = par;
        }

        //children push kora
        for(auto child : adj_list[par])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            } 
        }
    }
}
int main() {
    int n,e;
    cin>>n>>e;
   
   int first_node = -1 ;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        if(first_node == -1)
        {
            first_node = a;
        }

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    if(first_node == -1)
    {
        first_node = 0 ;
    }
    memset(vis,false,sizeof(vis)); 
    bfs(0);

    cout<<"maximum :"<<max1<<endl;
    cout<<"maximum :"<<max2<<endl;
    return 0;
}
//input:
// 7 7 
// 0 1
// 1 3
// 1 4
// 3 2
// 4 6
// 3 5
// 4 5

// output:
// 0 1 3 4 2 5 6