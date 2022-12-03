class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char,int> map;
        for(char& c : s){
            map[c]++;
        }
        vector<pair<char,int>> freq_pair;
        for(auto & it : map){
            freq_pair.push_back({it.first,it.second});
        }
        sort(begin(freq_pair),end(freq_pair),[&](const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second; 
        });
        string ans;
        for(auto& p : freq_pair){
            int x = p.second;
            while(x--){
                ans += p.first;
            }
        }
        return ans;
    }
};
