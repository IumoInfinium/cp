class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n,false);
        
        explore(0,rooms,vis);
        for(int i=0; i<n;i++){
            // cout << vis[i] << " ";
            if(!vis[i]) return false;
        }
        return true;
    }

    void explore(int node, vector<vector<int>>& rooms, vector<bool>& vis){
        vis[node] = true;
        if(!rooms[node].size()) return;
        for(int i : rooms[node])
            if(!vis[i]) explore(i,rooms,vis);
        return ;
    }
};
