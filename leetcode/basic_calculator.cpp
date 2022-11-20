class Solution {
public:
    int calculate(string s) {
        int result=0, sign=1,curr_digit = 0;
        int n=s.size();
        stack<int> st;
        
        for(int i=0;i<n ;i++){
            if(isdigit(s[i])){
                curr_digit = s[i]-'0';
                while(i+1< n && isdigit(s[i+1])){
                    curr_digit = curr_digit*10 + (s[i+1]-'0');
                    i++;
                }
                result  += curr_digit*sign;
            }
            else if(s[i] == '+') sign =1;
            else if(s[i] == '-') sign=-1;
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                result =0;
                sign=1;
            }
            else if(s[i] == ')'){
                int prev_sign = st.top(); st.pop();
                int prev_result = st.top(); st.pop();
                result = prev_result+ (result*prev_sign);
            }
        }
        return result;
    }
};
