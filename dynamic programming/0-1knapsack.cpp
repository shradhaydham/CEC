#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &wt,vector<int> &val,int n,int W)
{
    vector<int> prev(W+1,0);
    vector<int> curr(W+1,0);
    for(int i=wt[0];i<=W;i++)
    prev[i]=val[0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            int notTake=prev[j];
            int take=INT_MIN;
            if(wt[i]<=j)
            take=val[i]+prev[j-wt[i]];
            curr[j]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[W];
}
int main()
{
    int n;
    cin>>n;
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int W;
    cin>>W;
    int ans=knapsack(wt,val,n,W);
    cout<<ans;
    return 0;
}