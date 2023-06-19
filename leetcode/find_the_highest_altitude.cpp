class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int curr = 0;
        int i = 0;
        while(i< gain.size()){
            curr += gain[i];
            highest = max(highest, curr);
            i++;
        }
        return highest;
    }
};
