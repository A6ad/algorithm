#include <bits/stdc++.h>
using namespace std;


bool same_component(int n,int m,vector<vector<char>> &grid,int si,int sj,int di,int dj)
{
    if(si == di && sj == dj)
    return true;

    bool vis[1000][1000] = {false};

    queue<pair<int,int>> q;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty())
    {

        auto par = q.front();
        q.pop();

        int i = par.first;
        int j = par.second;

        for(auto x: dir)
        {
            int col_m = i + x[0];
            int row_m = j + x[1];

            if(col_m >= 0 && col_m<n && row_m >= 0 && row_m<m && grid[col_m][row_m]  == '.' && !vis[col_m][row_m] )
            {
                if(col_m == di && row_m == dj)
                return true;
                vis[col_m][row_m] = true;
                q.push({col_m,row_m});
            }    
        }
    }
    return false;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    
    int si,sj,di,dj;
    cin>>si>>sj;
    cin>>di>>dj;

    if(same_component(n,m,grid,si,sj,di,dj))
    {
        cout<<"YES"<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
    }
    return 0;
}