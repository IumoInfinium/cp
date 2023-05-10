class Solution {
public:
    // vector<string> ans;
    // vector<string> letterCombinations(string digits) {
    //     if(digits == "") return ans;
    //     unordered_map<char, vector<char>> mp;
    //     mp['2'] = {'a','b','c'};
    //     mp['3'] = {'d','e','f'};
    //     mp['4'] = {'g','h','i'};
    //     mp['5'] = {'j','k','l'};
    //     mp['6'] = {'m','n','o'};
    //     mp['7'] = {'p','q','r','s'};
    //     mp['8'] = {'t','u','v'};
    //     mp['9'] = {'w','x','y','z'};
        
    //     helper(0,"", digits,mp);
    //     return ans;
    // }

    // void helper(int idx, string curr, string& digits, unordered_map<char,vector<char>>& mp){
    //     if(idx == digits.size()){
    //         ans.push_back(curr);
    //         return;
    //     }
        
    //     int eles = mp[digits[idx]].size();
    //     for(int i=0; i<eles; i++){
    //         helper(idx+1, curr+ mp[digits[idx]][i], digits, mp);
    //     }

    //     return;
    // }

    vector<string> ans;
    vector<string> letterCombinations(string digits){
        if(digits == "") return ans;
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string curr= "";
        helper(0,curr, digits, mp);
        return ans;
    }

    void helper(int idx, string& curr, string& digits, vector<string>& mp){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        int eles = mp[digits[idx]-'0'].size();
        for(int i=0; i<eles; i++){
            curr.push_back(mp[digits[idx]-'0'][i]);
            helper(idx+1, curr, digits, mp);
            curr.pop_back();
        }
        return;
    }
};
