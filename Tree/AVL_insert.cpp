#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x):val(x),left(NULL),right(NULL){}
};
int height(Node *a){
    if(a==NULL)
    return 0;
    int lh=height(a->left);
    int rh=height(a->right);
    return 1+max(lh,rh);
}
int bal_factor(Node *root){
    if(root==NULL)
    return 0;
    return (height(root->left)-height(root->right));
}
Node *rightrotate(Node *a){
    Node *b=a->left;
    Node *temp=b->right;
    b->right=a;
    a->left=temp;
    return b;
}
Node *leftrotate(Node *a){
    Node *b=a->right;
    Node *temp=b->left;
    b->left=a;
    a->right=temp;
    return b;
}
Node* AVL_insert(Node* root,int key){
    Node *node=new Node(key);
    if(root==NULL)
    return node;
    Node *temp=root,*prev=NULL;
    while(temp){
        prev=temp;
        if(temp->val<key)
        temp=temp->right;
        else if(temp->val>key)
        temp=temp->left;
    }
    if(prev->val>key)
    prev->left=node;
    else
    prev->right=node;
    int bf=bal_factor(root);
    if(bf>1 && key<root->left->val)
    return rightrotate(root);
    else if(bf<-1 && key>root->right->val)
    return leftrotate(root);
    else if(bf>1 && key>root->left->val){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    else if(bf<-1 && key<root->right->val){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
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
int main()
{
    int n;
    cin>>n;
    int a[n];
    Node *root=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        root=AVL_insert(root,a[i]);
    }
    inorder(root);
    return 0;
}