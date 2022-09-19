class TwoSum {
    vector<int> arr;
    public:
    TwoSum() {
        
    }

    void add(int val) {
        arr.push_back(val);
    }

    bool find(int val) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int low=0,high=n-1;
        while(low<high){
            int x=arr[low] + arr[high];
            if(x==val) return true;
            else if(x>val) high--;
            else low++;
        }
        return false;
    }
};
