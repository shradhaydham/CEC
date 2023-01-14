#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],vector<int> &vis,int start)
{
    vis[start]=1;
    cout<<start<<" ";
    for(auto i:adj[start])
    {
        if(!vis[i])
        dfs(adj,vis,i);
    }
}
int main()
{
    int n,m;
    cout<<"Enter number of nodes and edges";
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n+1,0);
    dfs(adj,vis,1);
    return 0;
}