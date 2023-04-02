class Solution {
public:
    // vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    //     int n = spells.size();
    //     int m = potions.size();
    //     sort(begin(potions), end(potions));

    //     for(int i=0; i<n; i++){
    //         int low = 0, high = m-1;
    //         int mid;
    //         while(low <= high){
    //             mid = low + (high-low)/2;
    //             if(spells[i] >= success &&  potions[mid] >1) high=mid-1;
    //             else if(potions[mid] >= success && spells[i]>1) high=mid-1;
    //             else if((long)spells[i]* (long)potions[mid] >= success) high=mid-1;
    //             else low = mid+1;
    //         }
    //         spells[i] = m-low;
    //     }
    //     return spells;
    // }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
        int n=spells.size(), m = potions.size();

        sort(begin(potions), end(potions));

        for(int i=0; i<n; i++){
            spells[i] = potions.end() - upper_bound(begin(potions), end(potions), ((success-1 )/ spells[i]));
        }
        return spells;
    }
};
