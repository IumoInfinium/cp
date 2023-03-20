class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        if(!k) return true;
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(arr[i] == 0 && (i == 0 || arr[i-1]==0) && (i==n-1 || arr[i+1]==0)){
                arr[i]=1;
                k--;
                if(!k) return true;
            }
        }
        return false;
    }
};
