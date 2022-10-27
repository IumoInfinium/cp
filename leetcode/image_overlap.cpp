class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> a,b;
        int n = img1.size();
        
        // Making a map of (i,j) in index's, with 100 because of 2*N-1
        // And 100 is more than enough to handle it.
        // Trick index in  "i" -> i*100
        //              &  "j" -> j% n
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]) a.push_back(i*100 + j % n);
                if(img2[i][j]) b.push_back(i*100 + j % n);
            }
        }
        unordered_map<int,int> map;
        for(int i : a)
            for(int j : b)
                map[i - j]++;
        int res =0;
        for(auto it : map) res = max(res, it.second);
        return res;
    }
};
