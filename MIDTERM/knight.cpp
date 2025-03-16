#include <bits/stdc++.h>
using namespace std;

int knight(int n,int m,int k1,int k2,int q1,int q2)
{
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<int,int>> q;
    queue<int> steps;

    int move_i[] = {2,2,-2,-2,1,1,-1,-1};
    int move_j[] = {1,-1,1,-1,2,-2,2,-2};
    
    q.push({k1,k2});
    steps.push(0);
    vis[k1][k2] = true;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int step = steps.front();

        q.pop();
        steps.pop();

        if(x == q1 && y == q2)
        return step;

        for(int i=0;i<8;i++)
        {
            int move_x = x + move_i[i];
            int move_y = y + move_j[i];

            if(move_x >=0 && move_x<n && move_y>=0 && move_y<m && !vis[move_x][move_y])
            vis[move_x][move_y] = true;
            q.push({move_x,move_y});
            steps.push(step + 1); 
        }
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
    int n,m,k1,k2,q1,q2;
    cin>>n>>m;
    cin>>k1>>k2;
    cin>>q1>>q2;
    
    cout<<knight(n,m,k1,k2,q1,q2)<<endl;
   
     }
      return 0;
}