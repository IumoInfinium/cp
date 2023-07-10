#define pii pair<int,int>
class Solution {
public:
    // struct comp{
    //     const bool operator()(const pii &a , const pii& b){
    //         return a.first < b.first;
    //     }
    // };
    // int singleNumber(vector<int>& nums) {
    //     unordered_map<int,int> mp;
    //     priority_queue<pii, vector<pii>, comp> pq;

    //     for(int i=0; i< nums.size(); i++) mp[nums[i]]++;

    //     for(auto &it: mp){
    //         pq.push({it.second, it.first});
    //         if(pq.size() > 1) pq.pop();
    //     }

    //     return pq.top().second;
    // }

    int singleNumber(vector<int> nums){
        int ones=0, twos=0;

        for(int num : nums){
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};
