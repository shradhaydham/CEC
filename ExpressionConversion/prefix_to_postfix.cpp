#include<bits/stdc++.h>
using namespace std;
string convert(string s){
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push(op1+op2+s[i]);
        }
    }
    return st.top();
}
int main(){
    string s;
    cin>>s;
    cout<<"Prefix to postfix\n"<<convert(s);
    return 0;
}
