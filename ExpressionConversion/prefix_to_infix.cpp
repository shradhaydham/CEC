#include<bits/stdc++.h>
using namespace std;
string convert(string &s){
    reverse(s.begin(),s.end());
    stack<string> st;
    for(int i=0;i<s.size();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push(")"+op2+s[i]+op1+"(");
        }
    }
    string ans=st.top();
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<"Infix\n"<<convert(s);
    return 0;
}