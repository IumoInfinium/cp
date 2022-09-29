class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, h= arr.size()-k;
        while(l<h){
            int mid = (l+h)/2;
            if(x-arr[mid] > arr[mid+k]-x) l=mid+1;
            else h=mid;
        }
        return vector<int>(arr.begin()+l, arr.begin()+l+k);
    }
};
