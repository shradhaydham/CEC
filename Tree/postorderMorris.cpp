#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x):val(x),left(NULL),right(NULL){}
};
void insert(Node* &root,int key)
{
    Node *node=new Node(key);
    if(root==NULL)
    {
        root=node;
        return;
    }
    Node *prev=NULL,*temp=root;
    while(temp)
    {
        if(temp->val>key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->val<key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->val>key)
    prev->left=node;
    else
    prev->right=node;
}
void postorderMorris(Node *root){
    vector<int> ans;
    Node *curr=root;
    while(curr!=NULL){
        if(curr->right==NULL){
            ans.push_back(curr->val);
            curr=curr->left;
        }
        else{
            Node *temp=curr->right;
            while(temp->left!=NULL && temp->left!=curr){
                temp=temp->left;
            }
            if(temp->left==NULL){
                temp->left=curr;
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                temp->left=NULL;
                curr=curr->left;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"Post-order\n";
    for(auto i:ans){
        cout<<i<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    Node *root=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        insert(root,a[i]);
    }
    postorderMorris(root);
    return 0;
}