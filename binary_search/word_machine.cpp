
int solve(vector<string>& src) {
    stack<int> st;
    int a,b;
    for(int i=0;i<src.size();i++){
        if(src[i]=="-"){
            if(st.empty() || (st.size()<2)) return -1;
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a-b);
        }
        else if(src[i]=="+"){
            if(st.empty() || (st.size()<2)) return -1;
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            st.push(a+b);
        }
        else if(src[i]=="POP"){
            if(st.empty()) return -1;
            st.pop();
        }
        else if(src[i]=="DUP"){
            if(st.empty()) return -1;
            a=st.top();
            st.push(a);
        }
        else{
            a=stoi(src[i]);
            st.push(a);
        }
    }
    if(!st.empty()) return st.top();
    return -1;
}
