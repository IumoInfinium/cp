class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int x : piles) pq.push(x);
        int ans, x;
        while(k--){
            // here, ans is used like a temp variable
            x= pq.top();
            ans= x;
            pq.pop();
            pq.push(ans-(x/2));
        }
        // actual ans here
        ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
