bool static cmp(vector<int> &a, vector<int> &b) {
    return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
}

bool solve(vector<vector<int>> &nums) {
    sort(nums.begin(), nums.end(), cmp);
    vector<vector<int>> ret;
    for (auto &it : nums) {
        if (ret.empty())
            ret.push_back(it);
        else if (ret.back()[0] >= it[0])
            return true;
        else
            ret.push_back(it);
    }
    return false;
}
