#include<bits/stdc++.h>
using namespace std;
int lcs(string &s,string &t,int i,int j)
{
    if(i==s.size() || j==t.size())
    return 0;
    if(s[i]==t[j])
    return 1+lcs(s,t,i+1,j+1);
    else
    return max(lcs(s,t,i,j+1),lcs(s,t,i+1,j));
}
int main()
{
    string s="";
    string t="";
    cin>>s>>t;
    int ans=lcs(s,t,0,0);
    if(ans==-1)
    cout<<"No subsequence";
    else 
    cout<<"LCS "<<ans;
    return 0;
}
