class Solution {
public:

    int countDays(vector<int>& weights, int total, int curr=0, int days=1){
        for(auto w: weights){
            curr += w;
            if(curr > total) ++days, curr = w;
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0, high=0, mid=0;
        for(int w: weights){
            if(low < w) low = w;
            high+=w;
        }
        while(low < high){
            mid = (low + high)/2;
            if(countDays(weights, mid) <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
