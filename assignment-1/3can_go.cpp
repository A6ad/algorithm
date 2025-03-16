#include <bits/stdc++.h>
using namespace std;

char grid[1001][1001];
bool vis[1001][1001];

vector<pair<int,int>> direction ={{0,1},{0,-1},{1,0},{-1,0}};

int n,m;

bool valid (int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
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
        int child_row = x + direction[i].first;
        int child_col = y + direction[i].second;
        if(valid(child_row,child_col) && !vis[child_row][child_col] && grid[child_row][child_col] != '#')
        {
            dfs(child_row,child_col);
        }
    }
}

int main() {
    cin>>n>>m;

int start_col = -1,start_row =-1,end_row= -1,end_col = -1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == 'A')
            {
                start_row = i;
                start_col = j;
            }
            else if(grid[i][j] == 'B')
            {
                end_row = i;
                end_col = j;
            }
        }
    }    

    if(start_row == -1 ||start_col == -1 ||end_row == -1||end_col == -1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    memset(vis,false,sizeof(vis));
    dfs(start_row,start_col);

    if(vis[end_row][end_col])
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}