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
void inorder(Node * root){
    if(root==NULL)
    return;
    stack<Node*>st;
    Node *temp=root;
    while(1){
        if(temp!=NULL)
        {
            st.push(temp);
            temp=temp->left;
        }
        else{
            if(st.empty()) break;
            temp=st.top();
            st.pop();
            cout<<temp->val<<" ";
            temp=temp->right;
        }
    }
}
void remove(Node* &root,int key){
    if(root==NULL)return;
    Node *temp=root,*prev=NULL;
    while(temp){
        if(temp->val>key){
            prev=temp;
            temp=temp->left;
        }
        else if(temp->val<key){
            prev=temp;
            temp=temp->right;
        }
        else{
            if(temp->left==NULL && temp->right==NULL){
                if(prev->left->val==key)
                prev->left=NULL;
                else
                prev->right=NULL;
                delete(temp);
            }
            else if(temp->left==NULL){
                if(prev->left->val==key)
                prev->left=temp->right;
                else
                prev->right=temp->right;
                delete(temp);
            }
            else if(temp->right==NULL){
                if(prev->left->val==key)
                prev->left=temp->left;
                else
                prev->right=temp->left;
                delete(temp);
            }
            else{
                Node *succ=temp->right;
                Node* succParent=temp;
                while(succ->left!=NULL){
                    succParent=succ;
                    succ=succ->left;
                }
                temp->val=succ->val;
                if(succParent->left==succ)
                succParent->left=succ->right;
                else
                succParent->right=succ->right;
                delete(succ);
            }
            return;
        }
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
    int rem;
    cin>>rem;
    remove(root,rem);
    cout<<"\nInorder\n";
    inorder(root);
    return 0;
}