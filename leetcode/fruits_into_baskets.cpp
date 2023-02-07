class Solution {
public:
    // TLE
    // int totalFruit(vector<int>& fruits) {
    //     int n = fruits.size();
    //     if(n == 1) return 1;
    //     if(n == 2) return 2;
    //     int b1,b2;  // basket1 and basket2
    //     int count;
    //     int ans=1;

    //     for(int i=0; i<n; i++){
    //         b1= -1, b2 =-1;
    //         count = 0;
    //         int j=i;
    //         while(j < n){
    //             if     (b1 == -1) {b1 = fruits[j]; count=1;}
    //             else if(fruits[j] == b1) count++;
    //             else if(b2 == -1) {b2 = fruits[j]; count++;}
    //             else if(fruits[j] == b2) count++;
    //             else{
    //                 ans = max(ans, count);
    //                 break;
    //             }
    //             j++;
    //         }
    //         ans = max(ans,count)
    //     }
    //     return ans;
    // }

    int totalFruit(vector<int>& fruits){
        int n = fruits.size();
        if(n==1) return 1;
        if(n==2) return 2;
        
        int ans = 0;
        
        int b1 = -1, b2 = -1;
        int curr = 0, countLast = 0;

        for(int i=0; i<n; i++){
            if(fruits[i] == b1 || fruits[i] == b2) curr++;
            else curr = countLast+1;

            if(fruits[i] == b1) countLast++;
            else countLast =1;

            if(fruits[i] != b1){
                b2 = b1;
                b1 = fruits[i];
            }
            ans = max(ans, curr);
        }
        return ans;
    }

    // Submitted but avg. solution!
    // int totalFruit(vector<int>& fruits){
    //     unordered_map<int,int> map;

    //     int ans=1;
    //     int n=fruits.size();
    //     int i=0, j=0;
    //     while(i<n){
    //         map[fruits[i]]++;
    //         if(map.size() <= 2) ans = max(ans, i-j+1);
    //         else{
    //             if(map[fruits[j]] == 1) map.erase(fruits[j]);
    //             else map[fruits[j]]--;
    //             j++;
    //         }
    //         i++;
    //     }
    //     return ans;
    // }
};
