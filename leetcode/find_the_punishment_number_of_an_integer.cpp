class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;
        
        for(int i=1; i<=n; i++){
            if(dfs(i*i, i)) ans += i*i;
        }
        return ans;
    }
    
    
    bool dfs(int curr, int target){
        if(target<0) return false;
        if(curr == 0) return target == 0;
        
        int power = 10;
        while(curr * 10 >= power){
            if(dfs(curr/power, target - curr%power)) return true;
            power *= 10;
        }
        
        return false;
    }
};
