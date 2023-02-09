class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector< unordered_set<string> > arr(26);

        for(string & s: ideas) arr[s[0]-'a'].insert(s.substr(1));

        long long count = 0;

        for(int i=0; i<26; i++){
            for(int j=i+1; j<26; j++){
                long long cnt1 = 0L, cnt2 = 0L;

                for(auto& item : arr[i]){
                    // matches every sttring from set 1 with strings in set 2
                    if(!arr[j].count(item)) cnt1++; 
                }
                for(auto& item : arr[j]){
                    // matches every sttring from set 1 with strings in set 1
                    if(!arr[i].count(item)) cnt2++;
                }
                count += (cnt1 * cnt2);
            }
        }
        // count will be doubled when both new idea1 & new idea2 are not in given list of ideas
        return count * 2;
    }
};
