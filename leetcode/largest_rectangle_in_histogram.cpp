class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int ans = 0;

        arr.push_back(0);
        int n = arr.size();

        vector<int> idxs;
        for(int i=0; i<n ; i++){
            while(idxs.size() > 0 && arr[idxs.back()] >= arr[i]){
                int h = arr[idxs.back()];
                idxs.pop_back();

                int second_idx = idxs.size() > 0 ? idxs.back() : -1;
                ans = max(ans, h*(i-second_idx-1));
            }
            idxs.push_back(i);
        }
        return ans;
    }
};
