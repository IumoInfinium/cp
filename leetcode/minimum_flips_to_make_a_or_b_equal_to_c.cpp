class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> x(a), y(b), z(c);

        int ans=0;
        for(int i=0; i<32; i++){
            if(z[i] == 1){
                if(x[i] == 0 && y[i] == 0) ans++;
            }
            else{
                if(x[i] == 1) ans++;
                if(y[i] == 1) ans++;
            }
        }
        return ans;
    }
};
