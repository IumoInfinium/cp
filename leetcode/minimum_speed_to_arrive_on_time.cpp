class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour < dist.size()-1) return -1;

        int low = 1;
        int high = 1e7;

        while(low <= high){
            int mid = (low + high)/2;
            if(check(mid, hour, dist)) high = mid-1;
            else low = mid+1;
        }
        return low > 1e7 ? -1 : low;
    }

    bool check(int speed, double hour, vector<int>& dist){
        double time = 0;
        for(int i=0; i< dist.size(); i++){
            time = ceil(time);
            time += (double) dist[i] / speed;
            if(time > hour) return false;
        }
        return true;
    }
};
