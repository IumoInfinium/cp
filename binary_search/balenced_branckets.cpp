bool solve(string s) {
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') st.push('(');
        else{
            if(st.empty()) return false;
            st.pop();
        }
    }
    if(st.empty()) return true;
    return false;
}
