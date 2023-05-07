class FrequencyTracker {
public:
    unordered_map<int,int> mp;
    int arr[100006]={};
    FrequencyTracker() {
        
    }
    
    void add(int num) {
        if(mp.count(num)){
            arr[mp[num]]--;
        }
        mp[num]++;
        arr[mp[num]]++;
        
    }
    
    void deleteOne(int num) {
        if(mp.count(num) && mp[num]>0){
            arr[mp[num]]--;
            mp[num]--;
            arr[mp[num]]++;
        }
    }
    
    bool hasFrequency(int freq) {
        if(arr[freq]>0) return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
