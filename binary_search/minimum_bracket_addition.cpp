int solve(string s) {
    stack<char> st;
    int ans=0;
    for(char c:s){
        if(c=='(')st.push(c);
        else{
            if(st.size()>0) st.pop();
            else ans++;
        }
    }
    if(st.size()>0) ans+=st.size();
    return ans;
}
