#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int start,int n)
{
    int vis[n+1]={0};
    stack<int> st;
    st.push(start);
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!vis[u])
        {
            cout<<u<<" ";
            vis[u]=1;
        }
        for(auto i: adj[u])
        {
            if(!vis[i])
            st.push(i);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,1,n);
    return 0;
}