class Solution {
public:
    // string frequencySort(string& s) {
    //     unordered_map<char,int> map;
    //     for(char& c : s){
    //         map[c]++;
    //     }
    //     vector<pair<char,int>> freq_pair;
    //     for(auto & it : map){
    //         freq_pair.push_back({it.first,it.second});
    //     }
    //     sort(begin(freq_pair),end(freq_pair),[&](const pair<char,int>& a, const pair<char,int>& b){
    //         return a.second > b.second; 
    //     });
    //     string ans;
    //     for(auto& p : freq_pair){
    //         int x = p.second;
    //         while(x--){
    //             ans += p.first;
    //         }
    //     }
    //     return ans;
    // }

    string frequencySort(string& s){
        vector<pair<char,int>> freq(122,make_pair('a',0));
        for(char& c : s){
            freq[c-'0'] = {c,freq[c-'0'].second+1};
            // cout << freq[c-'0'].second <<endl;
        }
        string ans;
        sort(begin(freq),end(freq),[&](const pair<char,int>& a, const pair<char,int>& b){
            return a.second > b.second;
        });
        int x=0;
        for(auto&p : freq){
            x = p.second;
            if(!x) return ans;
            while(x--){
                ans+=p.first;
            }
        }
        return ans;
    }
};
