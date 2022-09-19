int solve(string s, string t) {
    int diff = s.size() - t.size();
    int mini = t.size();
    for(int i=0;i<=diff;i++){
        int count =0;
        int j=i;
        for(int k=0;k<t.size();k++){
            if(s[j]!= t[k]) count++;
            j++;
        }
        mini=min(mini,count);
    }
    return mini;
}
