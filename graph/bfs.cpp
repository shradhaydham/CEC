#include<bits/stdc++.h>
using namespace std;
void bfs(int n,vector<int> adj[])
{
    int visited[n+1]={0};
    visited[1]=1;
    queue<int> q;
    q.push(1);
    int level[n+1]={0};
    vector<int> ans;
    while(!q.empty())
    {
        int x=q.front();
        ans.push_back(x);
        q.pop();
        for(auto i:adj[x])
        {
            if(!visited[i])
            {
                level[i]=level[x]+1;
                visited[i]=1;
                q.push(i);
            }
        }
    }
    for(auto i:ans)
    cout<<i<<"  "<<level[i]<<endl;
}
int main()
{
    int n,m;
    cout<<"Enter number of nodes and edges\n";
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Node     Level\n";
    bfs(n,adj);
    return 0;
}