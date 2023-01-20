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
void preorder(Node *root){
    if(root==NULL)return;
    stack<Node*>st;
    st.push(root);
    Node *temp=NULL;
    while(!st.empty())
    {
        temp=st.top();
        st.pop();
        cout<<temp->val<<" ";
        if(temp->right!=NULL)
        st.push(temp->right);
        if(temp->left!=NULL)
        st.push(temp->left);
    }
}
void postorder(Node *root)
{
    if(root==NULL)return;
    stack<Node*>st;
    Node *curr=root;
    Node *temp=NULL;
    while(curr!=NULL || !st.empty()){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        else{
            temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                cout<<temp->val<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->val<<" ";
                }
            }
            else
            curr=temp;
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
    cout<<"Pre-order\n";
    preorder(root);
    cout<<"\nInorder\n";
    inorder(root);
    cout<<"\nPost-order\n";
    postorder(root);
    return 0;
}
