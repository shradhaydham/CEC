#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int> &par)
{
    if(par[x]==-1)
    return x;
    return par[x]=find(par[x],par);
}
void Union(int x,int y,vector<int> &par,vector<int> &rank)
{
    x=find(x,par);
    y=find(y,par);
    if(rank[x]<rank[y])
    par[x]=y;
    else if(rank[x]>rank[y])
    par[y]=x;
    else
    {
        par[x]=y;
        rank[y]++;
    }
}
void kruskal(vector<vector<int>> &adj,int n)
{
    vector<int> par(n,-1);
    vector<int> rank(n,0);
    sort(adj.begin(),adj.end());
    int ans=0;
    vector<vector<int>> mst;
    for(auto i:adj)
    {
        int u=i[1];
        int v=i[2];
        int w=i[0];
        u=find(u,par);
        v=find(v,par);
        if(u!=v)
        {
            ans+=w;
            mst.push_back({i[1],i[2]});
            Union(u,v,par,rank);
        }
    }
    cout<<"Mst = "<<ans<<endl;
    for(auto i:mst)
    cout<<i[0]<<" "<<i[1]<<endl;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj.push_back({w,u,v});
    }
    kruskal(adj,n);
    return 0;
}