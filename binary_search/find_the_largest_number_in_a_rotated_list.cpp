// int solve(vector<int>& arr) {
//     int low=0, high=arr.size()-1;
//     int maxi=INT_MIN;

//     while(low<=high){
//         int a=arr[low];
//         int b=arr[high];
//         maxi=max(maxi,max(a,b));
//         low++, high--; 
//     }
//     return maxi;
// }

int solve(vector<int>& arr){
    int low=0, high=arr.size()-1,mid,maxi=INT_MIN;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]<arr[0]) high=mid-1;
        else maxi=max(maxi,arr[mid]), low=mid+1;
    }
    return maxi;
}
