#include <bits/stdc++.h>
using namespace std;

    
int n,m;
char grid[1001][1001];
bool vis[1001][1001];
vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};

bool valid (int x,int y)
{
    if(x<0||x>=n || y<0||y>=m)
    {
        return false;
    }
    else 
    {
        return true;
    }
}

void dfs(int x,int y)
{
   vis[x][y] = true;
   for(int i=0;i<4;i++)
   {
    int child_row =x + dir[i].first;
    int child_col =y+ dir[i].second;

    if(valid(child_row,child_col)&&vis[child_row][child_col]==false &&grid[child_row][child_col] == '.')
    {
        dfs(child_row,child_col);
    }
}
}

int main() {
cin>>n>>m;
cin.ignore();
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        cin>>grid[i][j];
    }
}

memset(vis,false,sizeof(vis));
int count =0;

for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]=='.' && !vis[i][j])
        {
            count++;
            dfs(i,j);
        }
    }
}
cout<<count<<endl;
    return 0;
}