#include <bits/stdc++.h>
using namespace std;

int binsearch(vector<int>arr,int low,int high,int target){
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(arr[low]<arr[mid] && arr[mid]>target) high=mid;
        else if(arr[low]>arr[mid] && arr[])
    }
}
int search(vector<int>& nums, int target) {
    int n=nums.size(),mid;
    int low=0;
    int high=n-1;
    if(nums[low]==target) return low;
    else if(nums[high]== target) return high;
    else{
        return binsearch(nums,low,high,target);
        }
}

int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    cout<<search(nums,3);
    return 0;
}