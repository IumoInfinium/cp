class Solution {
public:
    
/*
    //<============= METHOD 1==================>
    int maxLength(vector<string>& arr) {
        return dfs(arr,"",0);
    }
    
    int dfs(vector<string>& arr, string s, int idx){
        unordered_set <char> set(s.begin(), s.end());
        if(set.size() != s.size()) return 0;
        
        int res = s.size();
        for(int i=idx; i <arr.size(); i++){
            res = max(res, dfs(arr, s+arr[i],i+1));
        }
        return res;
    }
*/
    //<============= METHOD 2==================>
    int maxLength(vector<string>& arr){
        vector<bitset<26>> nbits;
        for(string s : arr){
            bitset<26> tmp;

            // setting occurance of a char in bitset and push it to n-sized vector bitset
            for(char c : s) tmp.set(c-'a');
            if(tmp.count() == s.size()) nbits.push_back(tmp);

        }
        return dfs(nbits, bitset<26>(), 0);
    }

    int dfs(vector<bitset<26>>& nbits, bitset<26> curr, int idx){
        int res = curr.count();
        for(int i=idx; i < nbits.size(); i++){
            if( !(nbits[i] & curr).any())
                res = max(res, dfs(nbits, curr | nbits[i],i+1));
        }
        return res;
    }
};
