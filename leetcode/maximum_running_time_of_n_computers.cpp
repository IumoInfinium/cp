class Solution {
public:
    long long maxRunTime(int n, vector<int>& arr) {
        long long low = 0, high =accumulate(begin(arr), end(arr), 0LL);
    
        while(low < high){
            long long mid = (low + high +1)/2;
            long long minutes = 0;

            for(int x : arr) minutes += min((long long)x, mid);
            
            if(minutes >= n*mid) low = mid;
            else high = mid-1;
        }
        return low;
    }

};
