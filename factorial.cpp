#include <bits/stdc++.h>
using namespace std;
vector<int> v(999999);
int main() {
    v[0]= 1;
    int n;
    cin>>n;
    int i=0;
    for(i=1;i<=n;i++)
    {
        v[i] = v[i-1] * i;
    }
cout<<v[n]<<endl;
    return 0;
}