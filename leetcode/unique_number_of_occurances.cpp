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

        // better runtime than set
        // unordered_map<int,int> map;
        // int max_times=1;
        // for(int i : arr){
        //     map[i]++;
        //     if(map[i]>max_times) max_times = map[i];
        // }
        // vector<bool> counts(max_times,false);
        // for(auto& it : map){
        //     if(counts[it.second]) return false;
        //     counts[it.second]=true;
        // }
        // return true;

        // better memory usage
        int uniqs[1000]={0};
        int count=0;
        for(int i=0;i<arr.size(); i++){
            count =0;
            if(arr[i]==1001) continue;
            
            for(int j=i+1;j<arr.size(); j++){
                if(arr[i]==arr[j]){
                    count++;
                    arr[j]=1001;
                }
            }
            if(uniqs[count]) return false;
            uniqs[count]=1;
        }
        return true;

    }
};
