class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int n = prices.size();
        int l[n],r[n];
        int lmin=prices[0],rmax=prices[n-1], maxProfit=0;
        l[0]=0, r[n-1]=0;
        int i,j;
        for(i=1,j=n-2; i<n,j>=0; i++,j--){
            lmin= min(lmin,prices[i]);
            l[i]= max(l[i-1],prices[i]-lmin);
            
            rmax= max(rmax,prices[j]);
            r[j]= max(r[j+1],rmax-prices[j]);
        }
        for(int i=0;i<n;i++) maxProfit= max(maxProfit, l[i]+r[i]);
        return maxProfit;
    }
};
