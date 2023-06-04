class Solution {
public:
    int minimizedStringLength(string s) {
        int arr[26]={0};
        
        for(char &c : s) arr[c-'a']++;
        int ans =0;
        for(int i=0; i<26; i++) if(arr[i]) ans++;
        return ans;
    }
};
