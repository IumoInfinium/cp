class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n==1) return 1;

        int slow=0, fast =0;
        int count;
        while(fast < n){
            count = 1;
            while(fast < n-1 && chars[fast] == chars[fast+1]){
                count++;
                fast++;
            }
            chars[slow++] = chars[fast++];
            if(count>1){
                for(char c : to_string(count)) chars[slow++]=c;
            }
        }
        return slow;
    }
};
