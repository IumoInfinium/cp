class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int> st;     // stack using vector for all asteriods moving in right

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(arr[i] > 0) st.push_back(arr[i]);
            if(st.empty() && arr[i] < 0){
                ans.push_back(arr[i]);
                continue;
            }
            while(!st.empty() && arr[i] < 0){
                if(abs(st.back())> abs(arr[i])){
                    arr[i] = INT_MAX;
                }
                else if(abs(st.back() == abs(arr[i]))){
                    arr[i] = INT_MAX;
                    st.pop_back();
                }
                else{
                    st.pop_back();
                }
            }
            if(st.empty() && arr[i]<0) ans.push_back(arr[i]);
        }
        ans.insert(ans.end(), st.begin(), st.end());
        return ans;

    }
};
