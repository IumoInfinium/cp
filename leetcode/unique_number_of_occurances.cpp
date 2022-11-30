class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // unordered_map<int,int> map;
        // for(int i : arr) map[i]++;
        // unordered_set<int> s;
        // for(auto& it : map){
        //     if(s.count(it.second)) return false;
        //     s.insert(it.second);
        // }
        // return true;

        unordered_map<int,int> map;
        int max_times=1;
        for(int i : arr){
            map[i]++;
            if(map[i]>max_times) max_times = map[i];
        }
        vector<bool> counts(max_times,false);
        for(auto& it : map){
            if(counts[it.second]) return false;
            counts[it.second]=true;
        }
        return true;
    }
};
