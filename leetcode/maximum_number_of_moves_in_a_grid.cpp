class Solution {
  vector<vector<int>> directions{{-1,1},{0,1},{1,1}};
  
  bool isValid(int r, int c, vector<vector<int>>& grid) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return false;
    return true;
  }
  
  vector<vector<int>> dp;
  
  int countMoves(int r, int c, vector<vector<int>>& grid) {
    if (dp[r][c] != -1) return dp[r][c];
    
    int acc = 0;
    for (auto it : directions) {
      int newr = r+it[0];
      int newc = c+it[1];
      if (isValid(newr, newc, grid) && grid[newr][newc] > grid[r][c]) {
        acc = max(acc, 1 + countMoves(newr, newc, grid));
      }
    }
    return dp[r][c] = acc;
  }
  
public:
  int maxMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    dp.resize(n, vector<int>(m, -1));
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, countMoves(i, 0, grid));
    }
    return ans;
  }
};
