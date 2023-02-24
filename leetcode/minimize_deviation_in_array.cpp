class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans=INT_MAX, mini = INT_MAX;
        priority_queue<int> pq;

        for(int k : nums){
            k = k&1 ? k*2 : k;
            pq.push(k);
            mini = min(mini,k);
        }
        while(pq.top()%2==0){
            ans = min(ans, pq.top() - mini);
            mini = min(mini, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(ans, pq.top() - mini);
    }
};
