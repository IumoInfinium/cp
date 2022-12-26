class Solution {
public:
    bool canJump(vector<int>& nums){
        int maxCover = nums[0];
        for(int i=1; i < nums.size(); i++){
            if(maxCover < i) return false;
            maxCover = max(maxCover, i+nums[i]);
        }
        return true;
    }
    // bool bfs(int i, vector<vector<int>>& adj, vector<bool>& vis){
    //     if(i==vis.size()-1) return true;

    //     vis[i]=true;
    //     for(int x:adj[i]){
    //         bfs(x,adj,vis);
    //     }
    //     return false;
    // }
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> adj(n);
    //     int k;
    //     for(int i=0;i <n; i++){
    //         for(int k=0; k <= nums[i]; k++){
    //             if(k+i <n) adj[i].push_back(k+i);
    //         }
    //     }
    //     vector<bool> visited(n);

    //     return bfs(0,adj,visited);
    //     // stack<int> st;
    //     // st.push(0);

    //     // int stsize=0, curr=0;
        
    //     // while(!st.empty()){
    //     //     curr = st.top();
    //     //     st.pop();
    //     //     if(curr == n-1) return true;
    //     //     if(visited[curr]) continue;

    //     //     visited[curr] = true;
    //     //     for(int nei : adj[curr]){
    //     //         st.push(nei);
    //     //     }
    //     // }
    //     // return false;
    // }
};
