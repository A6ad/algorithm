#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];

int main() {
    int n,e,x,y;
    cin>>n>>e;
    while(e--)
    {
        cin>>x>>y;
        adj_list[x].push_back(y);
        //adj_list[y].push_back(x);
    }

    int q;
    cin>>q;
    while(q--)
    {
    int a,b;
    cin>>a>>b;
    bool connected = false;
    
    
        for(int child : adj_list[a])
        {
          if(child == b)
          {
            connected = true;
            break;
          }
        }
    if(a==b)
    {
      connected = true;
    }

    if (connected)
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
  }
   }
    