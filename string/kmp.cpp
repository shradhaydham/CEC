#include<bits/stdc++.h>
using namespace std;
int kmp(string text,string pattern)
{
    int n=text.size();
    int m=pattern.size();
    vector<int> lps(m,0);
    int prevlps=0;
    int i=1;
    while(i<m)
    {
        if(pattern[i]==pattern[prevlps])
        {
            lps[i]=prevlps+1;
            prevlps++;
            i++;
        }
        else if(prevlps==0)
        {
            lps[i]=0;
            i++;
        }
        else
        prevlps=lps[prevlps-1];
    }
    i=0;
    int j=0;
    while(i<n)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        i++;
        else
        j=lps[j-1];
        if(j==m)
        return i-m;
    }
    return -1;
}
int main()
{
    string text="";
    string pattern="";
    cin>>text>>pattern;
    int ans=kmp(text,pattern);
    if(ans==-1)
    cout<<"Pattern not found";
    else
    cout<<"Pattern found at index "<<ans;
    return 0;
}