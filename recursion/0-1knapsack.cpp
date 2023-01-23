#include<bits/stdc++.h>
using namespace std;
int knapsack(vector<int> &wt,vector<int> &val,int W,int ind)
{
    if(ind==0)
    {
        if(wt[0]<=W)
        return val[0];
        return 0;
    }
    int notTake=knapsack(wt,val,W,ind-1);
    int take=INT_MIN;
    if(wt[ind]<=W)
    take=val[ind]+knapsack(wt,val,W-wt[ind],ind-1);
    return max(take,notTake);
}
int main()
{
    int n;
    cin>>n;
    vector<int>wt(n);
    vector<int>val(n);
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    int W;
    cin>>W;
    int ans=knapsack(wt,val,W,n-1);
    cout<<"0/1 Knapsack "<<ans;
    return 0;
}