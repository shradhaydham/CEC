#include<iostream>
using namespace std;

void linearsearch(int arr[],int n,int key)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
        cout<<"key found at index"<<i;
        count=1;
        }
    }
    if(count==0)
    cout<<"not found";

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    linearsearch(arr,n,key);
    return 0;

}