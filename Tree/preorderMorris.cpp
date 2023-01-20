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
void preorderMorris(Node * root){
    vector<int> ans;
    Node *curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            ans.push_back(curr->val);
            curr=curr->right;
        }
        else{
            Node *temp=curr->left;
            while(temp->right!=NULL && temp->right!=curr){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right=curr;
                ans.push_back(curr->val);
                curr=curr->left;
            }
            else{
                temp->right=NULL;
                curr=curr->right;
            }
        }
    }
    cout<<"Pre-order\n";
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
    preorderMorris(root);
    return 0;
}