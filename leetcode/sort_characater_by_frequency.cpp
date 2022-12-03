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

    // string frequencySort(string& s){
    //     vector<pair<char,int>> freq(122,make_pair('a',0));
    //     for(char& c : s){
    //         freq[c-'0'] = {c,freq[c-'0'].second+1};
    //     }
    //     string ans;
    //     sort(begin(freq),end(freq),[&](const pair<char,int>& a, const pair<char,int>& b){
    //         return a.second > b.second;
    //     });
    //     int x=0;
    //     for(auto&p : freq){
    //         x = p.second;
    //         if(!x) return ans;
    //         while(x--){
    //             ans+=p.first;
    //         }
    //     }
    //     return ans;
    // }

    struct comp{
        constexpr bool operator()(pair<char,int> const& a, pair<char,int> const& b)
        const noexcept{
            return a.second < b.second;
        }
    };
    string frequencySort(string& s){
        vector<int> freq(122,0);
        string ans;
        int x=0;
        for(char & c : s){
            freq[c - '0']++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>, comp> q;
        for(int i=0; i<122;i++){
            if(!freq[i]) continue;
            q.push({'0'+i,freq[i]});
        }
        while(!q.empty()){
            x = q.top().second;
            while(x--){
                ans += q.top().first;
            }
            q.pop();
        }
        return ans;
    }
};
