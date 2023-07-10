class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1 || n == k) return 0;
        
        vector<int> arr;
        
        for (int i = 0; i < n-1; i++) arr.push_back(weights[i] + weights[i+1]);
        
        sort(arr.begin(), arr.end());

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < k-1; i++){
            minSum += arr[i];
            maxSum += arr[n-2-i];
        }
        return maxSum - minSum;
    }
};
