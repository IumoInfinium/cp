class Solution {
public:
    int maxIncreasingGroups(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        long long total = 0;
        long long count = 0;

        for(int i=0; i<n; i++){
            total += arr[i];
            
            if(total >= (count+1)*(count+2)/2){
                count++;
            }
        }
        return count;
    }
};
