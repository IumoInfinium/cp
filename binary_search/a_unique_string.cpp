bool solve(string s) {
    int arr[26]={0};
    for(char c:s){
        arr[c-'a']++;
    }
    for(int i=0;i<26;i++){
        cout<<arr[i];
        if(arr[i]>1) return false;
    }
    return true;
}
