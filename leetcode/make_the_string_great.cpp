class Solution {
public:
    string makeGood(string s) {
        // int n=s.size();
        // if(n==1) return s;
        // string ans;
        // for(char& c:s){
        //     if(!ans.empty() && (ans.back()^c) == 32) ans.pop_back();
        //     else ans.push_back(c);
        // }
        // return ans;
        int n= s.size();
        if(n==1) return s;
        stack<char> st;
        char c,lower,upper;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(s[i]);
            else{
                c = s[i];
                lower=tolower(c);
                upper=toupper(c);
                if(st.top()==upper && s[i]==lower) st.pop();
                else if(st.top()==lower && s[i]==upper) st.pop();
                else st.push(s[i]); 
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
