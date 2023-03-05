class Solution {
public:
    int passThePillow(int n, int time) {
        int i=0;
        bool f=true;
        while(time>0){
            if(f) i++;
            else i--;
            if(i==n-1) f= false;
            if(i==0) f=true;
            time--;
        }
        return i+1;
    }
};
