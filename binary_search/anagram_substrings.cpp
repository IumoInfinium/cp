int solve(string p, string s) {
    if(s.size() < p.size()) return 0;
    const int c=256;
    int ans=0, i=0;
    array<char,c>pmap; pmap.fill(0);
    array<char,c>smap; smap.fill(0);

    for(;i <p.size();i++){
        pmap[c-p[i]]++;
        smap[c-s[i]]++;
    }
    if(smap == pmap) ans++;
    for(;i<s.size();i++){
        smap[c-s[i]]++;
        smap[c-s[i-p.size()]]--;
        if(smap==pmap) ans++;
    }
    return ans;
}
