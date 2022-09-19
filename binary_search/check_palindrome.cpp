bool solve(string s) {
    int low=0, high=s.size()-1;
    if(s=="" || s.size()==1) return true;
    while(low<=high){
        if(s[low++]!=s[high--]) return false;
    }
    return true;
}
