int solve(string s) {
    vector<int> arr(26,0);
    for(int i=0;i<s.size();i++){
        arr[s[i]-'a']++;
        if(arr[s[i]-'a']>1) return i;
    }
    return -1;
}
