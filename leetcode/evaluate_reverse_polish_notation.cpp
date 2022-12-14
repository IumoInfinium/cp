class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        long x,y;
        for(int i=0;i<tokens.size(); i++){
            if(tokens[i] == "+"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(x+y);
            }
            else if(tokens[i] == "-"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(y-x);
            }
            else if(tokens[i] == "*"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(x*y);
            }
            else if(tokens[i] == "/"){
                x = st.top(); st.pop();
                y = st.top(); st.pop();
                st.push(y/x);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
