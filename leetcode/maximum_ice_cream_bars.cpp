class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs),end(costs));
        int i=0, n =costs.size();
        int ans=0;
        while(i<n && coins>0){
            if(costs[i]<=coins) {ans++;coins -= costs[i];}
            i++;
        }
        return ans;
    }
};
