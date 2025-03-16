#include <bits/stdc++.h>
using namespace std;
void fun(int x,int n)
{
    
    if(x>n)
    return ;
cout<<x<<" ";

    fun(x+1,n);
}
int main() {
    fun(1,5);
    return 0;
}