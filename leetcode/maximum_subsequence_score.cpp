class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // first of all, dp fails here!!
        long ans=0;
        long summ=0;

        vector<pair<int,int>> nums;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i< nums1.size(); i++){
            nums.emplace_back(make_pair(nums2[i], nums1[i]));
        }
        sort(begin(nums), end(nums), greater<>());

        for(auto & [mini, item] : nums){
            pq.push(item);
            summ += item;

            if(pq.size() > k){
                summ -= pq.top();
                pq.pop();
            }

            if(pq.size() == k) ans = max(ans,summ * mini);
        }
        return ans;
    }
};
