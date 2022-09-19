class Solution {
public:
    bool canConstruct(string s, string mag) {
        // // Using HashMap
        
        // unordered_map<char,int>map1;
        // for(auto x:mag) map1[x]++;
        // for(auto x:s){
        //     if(map1[x]==0) return false;
        //     map1[x]--;
        // }
        // return true;
        
        // Using array map
        
        int arr[26]={0};
        for(char x: mag) arr[x-'a']++;
        for(char x: s){
            if(arr[x-'a']==0)return false;
            arr[x-'a']--;
        }
        return true;
    }
};
