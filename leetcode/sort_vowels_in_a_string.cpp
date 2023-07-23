class Solution {
public:
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u' ,'A', 'E', 'I', 'O', 'U'};
    
    string sortVowels(string s) {
        vector<char> arr;
        
        for(int i=0; i< s.size(); i++){
            if(vowels.count(s[i]))  arr.push_back(s[i]);
        }
        
        sort(arr.begin(), arr.end());
        
        int p=0;
        for(int i=0; i< s.size(); i++){
            if(vowels.count(s[i])) s[i] = arr[p++];
        }
        return s;
    }
};
