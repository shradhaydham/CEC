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
void traversal(Node* root){
    if(root==NULL)return;
    stack<pair<Node*,int>> st;
    st.push({root,1});
    vector<int> pre,in,post;
    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            st.push({it.first->left,1});
        }
        else if(it.second==2){
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
            st.push({it.first->right,1});
        }
        else
        post.push_back(it.first->val);
    }
    cout<<"Pre-order\n";
    for(auto i:pre){
        cout<<i<<" ";
    }
    cout<<"\nIn-order\n";
    for(auto i:in){
        cout<<i<<" ";
    }
    cout<<"\nPost-order\n";
    for(auto i:post){
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
    traversal(root);
    return 0;
}