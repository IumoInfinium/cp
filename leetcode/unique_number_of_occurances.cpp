class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int i : arr) map[i]++;
        unordered_set<int> s;
        for(auto& it : map){
            if(s.count(it.second)) return false;
            s.insert(it.second);
        }
        return true;
    }
};
