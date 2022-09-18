class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size(), cows=0, bulls=0;
        int digits[10]={0};
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]) bulls++;
            else digits[secret[i]-'0']++;
        }
        for(int i=0;i<n;i++){
            if(guess[i]!=secret[i] && digits[guess[i]-'0']>0){
                cows++;
                digits[guess[i]-'0']--;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
