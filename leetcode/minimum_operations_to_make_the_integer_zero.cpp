class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 < num2) return -1;

        for(int x=1; x<=61; x++){
            long target = num1- (long)num2*x;
            if(__builtin_popcountll(target) <= x && x <= target) return x;
        }
        return -1;
    }
};
