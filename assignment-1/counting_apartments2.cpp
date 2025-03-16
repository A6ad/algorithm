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

int dfs(int x,int y)
{
   vis[x][y] = true;
   int roomcount = 1;
   for(int i=0;i<4;i++)
   {
    int child_row =x + dir[i].first;
    int child_col =y+ dir[i].second;

    if(valid(child_row,child_col)&&vis[child_row][child_col]==false &&grid[child_row][child_col] == '.')
    {
        roomcount+=dfs(child_row,child_col);
    }
}
return roomcount;
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

int count = 0;
vector<int> sizes;
for(int i=0;i<n;i++)
{
    for(int j=0;j<m;j++)
    {
        if(grid[i][j]=='.' && !vis[i][j])
        {
           int size = dfs(i,j);
           sizes.push_back(size);
        }
    }
}

sort(sizes.begin(),sizes.end());
if(sizes.empty())
{
    cout<<"0"<<endl;
}
for(int x:sizes)
{
    cout<<x<<" ";
}
cout<<endl;
    return 0;
}