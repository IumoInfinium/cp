iclass Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
        int n = rocks.size();
        int ans=0;

        // number of rocks to add
        for(int i=0; i<n; i++){
           rocks[i] = capacity[i]-rocks[i];
        }
        sort(begin(rocks), end(rocks), greater<int>());
        int i=n-1;
        while(i >= 0 && extra > 0){
            if(rocks[i] == 0) ans++;
            else{
                if(rocks[i] <= extra){
                    extra -= rocks[i];
                    ans++;
                }
            }
            i--;
        }
        return ans;
    }
};
