void swap(vector<int>& arr, int fi, int si, int d){
    int i, temp; 
    for(i = 0; i < d; i++){ 
        temp = arr[fi + i]; 
        arr[fi + i] = arr[si + i]; 
        arr[si + i] = temp; 
    } 
} 
vector<int> solve(vector<int>& arr, int d) {
    int n=arr.size();
    if(d==0 || d==n) return arr;
    if(d>n) d%=n;
    int i=d;
    int j=n-d;
    while(i!=j){
        if(i<j){
            swap(arr,d-i,d+j-i,i);
            j-=i;
        }
        else{
            swap(arr,d-i,d,j);
            i-=j;
        }
    }
    swap(arr,d-i,d,i);
    return arr;
}
