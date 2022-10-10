class Solution {
public:
    string breakPalindrome(string p) {
        // int n= p.size();
        // if(n==1 ) return "";
        // string res="";
        // if(n>1){
        //     bool a=true;
        //     res=p;
        //     for(int i=0;i<n/2;i++){
        //         if(p[i]!='a'){
        //             a=false;
        //             res[i]='a';
        //             break;
        //         }
        //     }
        //     if(a) res[n-1]='b';
        // }
        // return res;
        int n=p.size();
        if(n==1) return "";
        for(int i=0;i<n/2;i++){
            if(p[i]!='a'){
                p[i]='a';
                return p;
            }
        }
        p[n-1]='b';
        return p;
    }
};
