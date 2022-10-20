class Solution {
public:
    string intToRoman(int num) {
        const int ints[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        const string romans[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i=0;i<13;i++){
            if(num/ints[i]!=0){
                res += romans[i];
                num -= ints[i];
                i--;
            }
        }
        return res;
    }
};
