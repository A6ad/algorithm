#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,e;
  cin>>n>>e;

  vector<int>adj_list[n];
  for(int i=0;i<e;i++)
  {
    int p,q;
    cin>>p>>q;
    adj_list[p].push_back(q);
    adj_list[q].push_back(p);
  }

  int q;
  cin>>q;

  for(int i=0;i<q;i++)
  {
    int x;
    cin>>x;

    if(adj_list[x].empty())
    {
        cout<<"-1"<<endl;
    }
    else 
    {
        sort(adj_list[x].rbegin(),adj_list[x].rend());
        for(int node : adj_list[x])
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }


  }



    return 0;
}