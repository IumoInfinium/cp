class Solution {
public:
    // int findKthPositive(vector<int>& arr, int k) {
    //     for(int i : arr) if(i<=k) k++;
    //     return k;
    // }
     
    // Even though, Binary Search, it is less efficient compared to above solution
    int findKthPositive(vector<int>& arr, int k){
        int m;
        int l = 0, h = arr.size();
        while(l<h){
            m = (l+h)/2;
            if(arr[m] - m - 1 < k) l=m+1;
            else h=m;
        }
        return h+k;
    }
};
