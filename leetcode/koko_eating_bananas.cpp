class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int t) {
        int low = 1, high = INT_MAX;
        int mid;
        for(int item : piles) high = max(high,item);
        
        while(low < high){
            mid = low+(high-low)/2;
            int count =0;
            for(int item : piles){
                count += (item+mid-1)/mid;
            }
            if(count <= t )
                high = mid;
            else low = mid+1;
        }
        return low;
    }
};
