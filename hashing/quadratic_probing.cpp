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
        ind=(ind+i*i)%n;
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
        ind=(ind+i*i)%n;
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
    cin>>n;
    arr.resize(n,INT_MIN);
    while(1){
    cout<<"1. Insert\n2. Remove\n";
    int ch;
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            int m;
            cin>>m;
            for(int i=0;i<m;i++)
            {
                int k,v;
                cin>>k>>v;
                insert(k,v,n);
            }
            break;
        }
        case 2:
        {
            int m;
            cin>>m;
            for(int i=0;i<m;i++)
            {
                int k,v;
                cin>>k>>v;
                remove(k,v,n);
            }
            break;
        }
        default:
        {
            cout<<"Invalid input";
            exit(0);
        }
    }
    cout<<"Press 1 to continue and 0 to exit";
    int t;
    cin>>t;
    if(t==0)
    break;
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=INT_MIN){
            cout<<"key = "<<i<<"   value = "<<arr[i]<<endl;
        }
    }
    return 0;
}