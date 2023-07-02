class Solution {
public:

    struct T{
        int i;
        int j;
        int summ;
        T(int i, int j, int summ): i(i), j(j), summ(summ){}
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        auto comp = [&](const T& a, const T& b){ return a.summ > b.summ; };
        
        priority_queue<T, vector<T>, decltype(comp)> pq(comp);

        for(int i=0; i<k && i<nums1.size(); i++) pq.emplace(i, 0, nums1[i] + nums2[0]);

        while(!pq.empty() && ans.size() < k){
            const auto [i,j, summ] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if(j+1 < nums2.size()) pq.emplace(i, j+1, nums1[i] + nums2[j+1]);
        }
        return ans;
    }
};
