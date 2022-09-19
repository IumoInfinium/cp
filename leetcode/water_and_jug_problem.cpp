class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        int x= jug1, y=jug2;
        int z= x+y;
        int steps[4] = {x,-x,-y,y};
        queue<int> q;
        
        vector<bool> visited(z+1,false);
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()){
            int val = q.front();
            q.pop();
            if(val == target) return true;
            for(int change : steps){
                int newVal = val + change;
                if(newVal >=0 && newVal <=z && visited[newVal]==false){
                    q.push(newVal);
                    visited[newVal]=true;
                }
            }
        }
        return false;
    }
};
