class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev,ans="1";
        int i,j,prev_size;
        for(int k=2; k<=n;k++){
            prev = ans;
            i=0, prev_size=prev.size();
            ans="";
            while(i<prev_size){
                j=i;
                while(i < prev_size && prev[i]==prev[j]) i++;
                ans += to_string(i-j) + prev[j];
            }
        }
        return ans;
    }
};
