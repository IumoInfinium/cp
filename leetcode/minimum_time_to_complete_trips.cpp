class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long ans=-1;
        long l = 1, h = 1e14, m, curr;
        while(l<=h){
            m = l+(h-l)/2;
            curr = 0;
            for(int t: time) curr+= m/t;

            if(curr >= totalTrips){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};
