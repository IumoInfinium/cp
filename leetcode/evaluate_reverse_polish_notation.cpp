class Solution {
public:
    int a,b;

    void getValues(stack<int>& st){
        a = st.top(); st.pop();
        b = st.top(); st.pop();
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string& s : tokens){
            if(s  == "+"){
                getValues(st); st.push(a+b);
            }
            else if(s == "-"){
                getValues(st); st.push(b-a);
            }
            else if(s == "*"){
                getValues(st); st.push(a*b);
            }
            else if(s == "/"){
                getValues(st); st.push(b/a);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
