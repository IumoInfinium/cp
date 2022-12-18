class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // int n = temp.size();
        // vector<int> ans(n,0);
        
        // for(int i =n-1; i>=0; i--){
        //     int x =0 ;
        //     for(int j=i;j <n ;j++){
        //         if(temp[i]< temp[j]){
        //             ans[i] = x;
        //             break;
        //         }
        //         else x++;
        //     }
        // }
        // return ans;

        stack<int> st;
        int n = temp.size();
        vector<int> ans(n);
        for(int i =0;i < n;i++){
            while(!st.empty() && temp[st.top()] < temp[i]){
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
