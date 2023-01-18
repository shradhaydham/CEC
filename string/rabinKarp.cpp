#include<bits/stdc++.h>
using namespace std;
#define d 256
int search(string &text,string &pattern)
{
    int q=INT_MAX;
    int n=text.size();
    int m=pattern.size();
    int p=0,t=0;
    int h=1;
    for(int i=0;i<m-1;i++)
    h=(h*d)%q;

    for(int i=0;i<m;i++)
    {
        p=(p*d+'pattern[i]')%q;
        t=(t*d+'text[i]')%q;
    }

    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            int j;
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                break;
            }
            if(j==m)
            return i;
        }
        if(i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;
        }
        if(t<0)
        t=t+q;
    }
    return -1;
}
int main()
{
    string text="";
    string pattern="";
    cin>>text>>pattern;
    int ans=search(text,pattern);
    if(ans==-1)
    cout<<"Pattern not matched";
    else
    cout<<"pattern found at index "<<ans;
    return 0;
}