class Solution {
    public:
        int uniquePaths(int m, int n) {
            // int highestPath=max(m,n)+1;
            // vector<int vector<int>> comb;
            vector<int> comb(n,1);
            for(int i=1;i<m;i++)
                for(int j=1;j<n;j++)
                    comb[j]+=comb[j-1];
            return comb[n-1];
        }
};
