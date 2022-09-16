class Solution {
public:
    int divide(int dvd, int div) {
        if(dvd==div) return 1;
        if(div==1) return dvd;
        if(dvd==0 || div==INT_MIN) return 0;
        if(dvd==INT_MIN && div==-1) return INT_MAX;
        int f=1;
        if((dvd>>31)^(div>>31)) f=-1;
        if(dvd>0) dvd=-dvd;
        if(div>0) div=-div;
        if(div<dvd) return 0;
        int quo=0;
        int sub=div;
        int cnt=1;
        while(true){
            while(sub>=INT_MIN/2 && dvd-(sub+sub)<0){
                sub+=sub;
                cnt+=cnt;
            }
            dvd-=sub;
            quo+=cnt;
            
            sub=div;
            cnt=1;
            if(dvd>div) break;
        }
        return f>0 ? quo:-quo;
    }
};
