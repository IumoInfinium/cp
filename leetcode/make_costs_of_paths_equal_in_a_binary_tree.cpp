class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        if(n==1) return 0;
        int i;
        int ans=0;
        for(i=n-1; i; i-=2){

            // if left node is big, update right node & ans
            if(cost[i-1] > cost[i]){
                ans += cost[i-1] - cost[i];
                cost[i] = cost[i-1];
            }
            // if right node is big, update left node & ans
            else if(cost[i-1] < cost[i]){
                ans += cost[i] - cost[i-1];
                cost[i-1] = cost[i];
            }

            // update parent node's value with child node's value
            cost[i-1 >> 1] += cost[i];
        }
        return ans;
    }
};
