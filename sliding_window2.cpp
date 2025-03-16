#include<bits/stdc++.h>
using namespace std;
int main()
{
vector<int> s={-2,10,1,3,-1,4,5};
int k=3, sum=0, ans=INT_MAX;
for(int i=0; i<k; i++)
{
sum+=s[i];
}
ans=sum;
for(int i=1; i<s.size(); i++)
{
sum= sum-s[i-1]+s[i+k-1];
ans=min(sum, ans);
}
cout<<ans<<endl;

return 0;
}