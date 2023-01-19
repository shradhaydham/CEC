#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int h(int k,int n){
    return k%n;
}
void insert(int k,int v,int n)
{
    int ind=h(k,n);
    int i=1;
    while(arr[ind]!=INT_MIN)
    {
        ind=(ind+i)%n;
        i++;
    }
    if(i==n){
        cout<<"Value cannot be inserted";
        return;
    }
    arr[ind]=v;
}
void remove(int k,int v,int n)
{
    int ind=h(k,n);
    int i=1;
    while(arr[ind]!=v)
    {
        ind=(ind+i)%n;
        i++;
    }
    if(i==n)
    {
        cout<<"No such value present in table";
        return;
    }
    arr[ind]=INT_MIN;
}
int main()
{
    int n,m;
    cin>>n>>m;
    arr.resize(n,INT_MIN);
    for(int i=0;i<m;i++)
    {
        int k,v;
        cin>>k>>v;
        insert(k,v,n);
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=INT_MIN){
            cout<<"key = "<<i<<"   value = "<<arr[i]<<endl;
        }
    }
    return 0;
}
