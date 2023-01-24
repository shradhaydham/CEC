#include<bits/stdc++.h>
using namespace std;
int priority(char c){
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}
string convert(string s){
    string ans;
    stack<char> st;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')
        s[i]=')';
        else if(s[i]==')')
        s[i]='(';
    }
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        ans+=s[i];
        else if(s[i]=='(')
        st.push('(');
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                char c=st.top();
                st.pop();
                ans+=c;
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                char c=st.top();
                st.pop();
                ans+=c;
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        char c=st.top();
        st.pop();
        ans+=c;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s="";
    cin>>s;
    cout<<"Prefix\n"<<convert(s);
    return 0;
}