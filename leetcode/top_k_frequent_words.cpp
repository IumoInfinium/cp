class Solution {
public:
    const static bool sortWith(const pair<string,int>& a,const  pair<string,int>& b){
        if(a.second==b.second) return a.first<b.first;
        return a.second > b.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> map;
        for(int i=0;i<words.size();i++){
            map[words[i]]++;
        }
        // for(auto x:map){
        //     cout<<x.first <<" "<<x.second<<"\n";
        // }
        vector<pair<string,int>> tmp;
        for(auto it: map){
            tmp.push_back({it.first,it.second});
        }
        sort(tmp.begin(),tmp.end(),sortWith);
        // for(auto x:tmp){
        //     cout<<x.first <<" "<<x.second<<"\n";
        // }
        for(int i=0;i<k;i++) ans.push_back(tmp[i].first);
        return ans;
    }
};

//============================ METHOD-2==================================
class compare{
public:
    const bool operator()(const pair<int,string>& a, const pair<int,string>& b){
        // Sort on same freq., but lexicographically on string.
        if(a.first==b.first)
            return a.second>b.second;
        // Sort on decreasing frequency
        return a.first<b.first;
    }
};

class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        
        for(string s: words) map[s]++;
        
        priority_queue<pair<int,string>, vector<pair<int,string>>, compare> pq;
        for(auto it :map) pq.push({it.second,it.first});
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
