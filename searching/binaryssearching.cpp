#include<bits/stdc++.h>
using namespace std;

int search(int a[],int l,int r,int k)
{
    if(r>=l)
    {
        int mid=r-(r-l)/2;
        if(a[mid]==k)
            return mid;
        else if(a[mid]>k)
            return search(a,l,mid-1,k);
        else
            return search(a,mid+1,r,k);
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter a sorted array\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cin>>key;
    int index=-1;
    index=search(a,0,n-1,key);
    if(index==-1)
    cout<<"Key not found";
    else
    cout<<"Key found at index "<<index;
    return 0;
}