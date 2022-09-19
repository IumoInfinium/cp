int solve(vector<string>& words, string letters) {
    int arr[26]={0};
    for(char x:letters)
        arr[x-'a']++;

    int arrtmp[26]={0};
    int maxi=0;
    for(string s: words){
        copy(arr,arr+26,arrtmp);
        // arrtmp=arr;
        int tmp=0;
        for(char c:s){
            if(arr[c-'a']==0) break;
            if(arrtmp[c-'a']>0)tmp++,arrtmp[c-'a']--;
        }
        if(tmp==s.size()) maxi=max(maxi,tmp);
    }
    return maxi;
}
