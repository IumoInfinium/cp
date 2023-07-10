class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        return max(helper('T', k, s), helper('F', k, s));
    }

    int helper(char c, int k, string& s){
        int left = 0;
        int n = s.size();
        int ans = 0, count = 0;

        for(int i=0; i<n; i++){
            if(s[i] == c) count++;
            while(count > k){
                if(s[left] == c) count--;
                left++;
            }
            ans = max(ans, i-left+1);
        }
        return ans;
    }
};
