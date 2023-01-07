#include<bits/stdc++.h>
using namespace std;

int jump_search(int a[],int n,int k)
{
    int steps=sqrt(n);
    int prev=0;
    while(a[min(steps,n)-1]<k)
    {
        prev=steps;
        steps+=sqrt(n);
        if(prev>=n)
        return -1;
    }
    while(a[prev]<k)
    {
        prev++;
        if(prev==min(steps,n))
        return -1;
    }
    if(a[prev]==k)
    return prev;
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    int key;
    cout<<"Enter sorted array\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    cin>>key;
    int index=jump_search(a,n,key);
    if(index==-1)
    cout<<"Key not found";
    else
    cout<<"Key found at index "<<index;
    return 0;
}