class Solution {
public:
    int minFlipsMonoIncr(string& s) {
        // int n = s.size();
        // vector<int> bits;
        // for(char& c : s) bits.push_back(c-'0');

        // int xor1=0,xor2=0,i=0;
        
        // while(i<n && bits[i]!=1) i++;
        
        // for(i;i<n;i++){
        //     xor1+= bits[i]^0;
        //     xor2+= (bits[i]^1);
        // }
        // return min(xor1,xor2);

        // dp-based solution
        int count=0,flips=0;
        for(char& c: s){
            if(c == '1') ++count;
            else ++flips;
            flips = min(count,flips);
        }
        return flips;
    }
};
