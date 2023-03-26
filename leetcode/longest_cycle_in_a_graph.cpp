class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans = -1;
        int n = edges.size();

        vector<bool> vis(n,false);
        vector<int> memo(n,0);
        for(int start = 0; start < n; start++){
            if(!vis[start]){
                int slow = start, fast = start;
                while(edges[fast] != -1 && edges[edges[fast]]!=-1){
                    slow = edges[slow];
                    fast = edges[edges[fast]];
                    // cycle_size++;
                    if(slow == fast) {
                        int cycle_len = 1;
                        slow = edges[slow];
                        while(slow != fast){
                            cycle_len++;
                            slow = edges[slow];
                        }
                        ans = max(ans, cycle_len);
                        memo[start] = cycle_len;
                        vis[start] = true;
                        break;
                    }

                    if(memo[slow] != 0){
                        memo[start] = memo[slow];
                        vis[start] = true;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
