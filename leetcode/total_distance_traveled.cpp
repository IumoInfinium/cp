class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        while(mainTank >= 5){
            ans += 5*10;
            mainTank -= 5;
            if(additionalTank >= 1){
                mainTank +=1;
                additionalTank -=1;
            }
        }
        ans += mainTank*10;
        return ans;
    }
};
