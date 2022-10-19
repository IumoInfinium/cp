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
