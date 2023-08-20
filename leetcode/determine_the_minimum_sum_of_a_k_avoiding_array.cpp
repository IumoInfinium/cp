class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> arr;
        
        unordered_set<int> sett;
        int curr =1;
        
        while(arr.size() < n){
            if(!sett.count(curr) && (!sett.count(k-curr)) || ((k - curr == curr))){
                arr.push_back(curr);
                sett.insert(curr);
            }
            curr++;
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};
