#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int h(int k,int n){
    return k%n;
}
void insert(int k,int v,int n)
{
    int ind=h(k,n);
    arr[ind].push_back(v);
}
void remove(int k,int v,int n)
{
    int ind=h(k,n);
    for(auto i=arr[ind].begin();i!=arr[ind].end();i++)
    {
        if(*i==v)
        {
            arr[ind].erase(i);
            return;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    arr.resize(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int k,v;
        cin>>k>>v;
        insert(k,v,n);
    }
    remove(5,2,n);
    for(int i=0;i<n;i++)
    {
        for(auto j:arr[i])
        {
            cout<<"key = "<<i<<"    value = "<<j<<endl;
        }
    }
    return 0;
}