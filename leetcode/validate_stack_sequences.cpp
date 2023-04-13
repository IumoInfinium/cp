class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> st;
        int i=0;

        for(auto &it : pushed){
            st.push_back(it);
            while(st.size() && st[st.size()-1] == popped[i]){
                st.pop_back();
                i++;
            }
        }
        return pushed.size() == i;
    }
};
