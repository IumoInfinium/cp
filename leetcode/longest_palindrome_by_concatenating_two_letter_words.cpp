class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        
        int unpaired=0;
        int ans=0;
        for(string w:words){
            if(w[0] == w[1]){
                // both chars same, use two of these and palindrome
                if(map[w]>0){
                    unpaired--;
                    map[w]--;
                    ans+=4;
                }
                else{
                    // found one new member having both
                    // chars same, updating map, and choices
                    // for unpaired
                    map[w]++;
                    unpaired++;
                }
            }
            else{
                // check if w's reverse is in map
                // if yes, we got to increase size by 4
                // else add new individual to map.
                string rev = w;
                reverse(rev.begin(),rev.end());
                if(map[rev]>0){
                    ans+=4;
                    map[rev]--;
                }
                else map[w]++;
            }
        }
        // if there are still some choices available
        // we can get 1 more choice, because currently
        // we only have even-lengthed palindrome.
        // we can insert new choice in center, and increase size
        if(unpaired >0) ans+=2;
        return ans;
    }
};
