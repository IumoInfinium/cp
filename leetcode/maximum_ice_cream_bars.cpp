class Solution {
public:
    // int maxIceCream(vector<int>& costs, int coins) {
    //     sort(begin(costs),end(costs));
    //     int i=0, n =costs.size();
    //     int ans=0;
    //     while(i<n && coins>0){
    //         if(costs[i]<=coins) {ans++;coins -= costs[i];}
    //         i++;
    //     }
    //     return ans;
    // }
    
    int maxIceCream(vector<int>& costs, int coins) {
        int freq[100001]={0};
        int maxi=INT_MIN;
        for(int& i : costs){
            freq[i]++;
            if(i > maxi) maxi=i;
        }
        int i=0,ans=0;
        while(coins>0 && i<=maxi){
            if(freq[i]>0 && i <=coins){ans++; coins-=i;freq[i]--;}
            else i++;
        }
        return ans;
    }
};
