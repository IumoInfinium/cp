class Solution {
public:
    // int minStoneSum(vector<int>& piles, int k) {
    //     priority_queue<int> pq;
    //     for(int x : piles) pq.push(x);
    //     int ans, x;
    //     while(k--){
    //         // here, ans is used like a temp variable
    //         x= pq.top();
    //         ans= x;
    //         pq.pop();
    //         pq.push(ans-(x/2));
    //     }
    //     // actual ans here
    //     ans=0;
    //     while(!pq.empty()){
    //         ans+=pq.top();
    //         pq.pop();
    //     }
    //     return ans;
    // }

    int minStoneSum(vector<int>& piles, int k){
        // assigning buckets to every element and then reducing backwards
        int freq[10001]={0};
        int maxi=-1;
        for(int i : piles){
            freq[i]++;
            maxi = max(maxi,i);
        }
        for(int i= maxi; i>=1 && k>0; i--){
            while(freq[i] != 0 && k>0){
                freq[i]--;
                freq[(i+1)/2]++;
                k--;
            }
        }
        int ans=0;
        for(int i=maxi; i>0; i--)
            ans += freq[i]*i;
        return ans;
    }
};
