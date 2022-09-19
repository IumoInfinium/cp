int solve(vector<string>& shows, vector<int>& durations, int k) {
    unordered_map <string,int> map;

    for(int i=0;i<(int)shows.size();i++)
        map[shows[i]]+=durations[i];

    vector<int> all;
    for(auto c: map){
        all.push_back(c.second);
    }
    sort(all.begin(),all.end(),greater<int>());
    int ans=0;
    for(int i=0;i<k;i++) ans+=all[i];
    return ans;
}
