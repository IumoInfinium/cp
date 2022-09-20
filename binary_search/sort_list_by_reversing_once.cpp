// Correct approach, wrong answer
 
// bool solve(vector<int>& nums) {
//     // array can be divided in 3 parts... increasing - decreasing - increasing
//     // this is will sure there is always a decreasing subarray that can be reversed to form a sorted array, but
//     // there are some edge cases like ->  1,2,3,10,4,1,13;
//     // Clearly the decreasing subarray is 10,4,1
//     // but on reversing it, doesn't makes it sorted, so we need to check their
//     // connecting edges too to make sure it could be sorted


//     int n=nums.size();
//     if(n==1) return true;
//     int i=1;

//     // 1st part-> increasing subarray
//     for (i=1; i < n && nums[i-1] < nums[i]; i++);
//     if(i==n) return true;       //2 and 3 part doesn't exit;

//     // 2nd part-> decreasing subarray
//     int j=i;
//     while(j<n && nums[j]<nums[j-1]){
//         if(i>1 && nums[j] <nums[i-2]) return false;
//         j++;
//     }
//     if(j==n) return true;   // 3 part doesn't exist so true;

//     // 3rd part-> increasing subarray again
//     int k=j;
//     if(nums[k]<nums[i-1]) return false;       // edge-condition on last of SA1 and SA3
    
//     while(k>1 && k<n){
//         if(nums[k]< nums[k-1]) return false;
//         k++;
//     }

//     // No fail condition, so true
//     return true;
// }

bool solve(vector<int>& arr){
    vector<int> tmp=arr;
    int n=arr.size();
    sort(begin(arr),end(arr));
    int i;
    for(i=0; i<n; i++)
        if(tmp[i]!= arr[i]) break;
    int j;
    for(j=n-1;j>=0;j--)
        if(tmp[j]!=arr[j]) break;
    
    // No decreasing part exists
    if(i>=j) return true;

    // Verfying that the decresing subarray really is decreasing or not
    do{
        i++;
        if(arr[i-1]< arr[i]) return false;
    }while(i!=j);
    return true;
}
