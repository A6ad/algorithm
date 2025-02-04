#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,e;
    cin>>n>>e;
    int adj_mat [n][n] ;

        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {                           // shortcut 
            adj_mat[i][j] = 0;      //memset(adj_mat,0,sizeof(adj_mat))
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<e;j++)
        {
            if(i==j){
            adj_mat[i][j] = 1;
            }
        }
    }

    

    for(int i = 0 ;i < e ;i++)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
    }
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj_mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// input: 
// 5 5
// 0 1
// 0 2
// 1 2
// 1 3
// 3 4

// output:
// 1 1 1 0 0 
// 0 1 1 1 0
// 0 0 1 0 0
// 0 0 0 1 1
// 0 0 0 0 1
