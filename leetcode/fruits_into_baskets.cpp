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
    //         ans = max(ans,count);
    //     }
    //     return ans;
    // }

    // WRONG ANSWER
    // int totalFruit(vector<int>& fruits){
    //     int n = fruits.size();
    //     if(n==1) return 1;
    //     if(n==2) return 2;

    //     int b1 = fruits[0];
    //     int b2 = fruits[1];
    //     if(b1 == b2) b2 = -1;
    //     int ans = 1, count = 2;
    //     for(int i=2; i<n; i++){
    //         if(fruits[i] == b1 || fruits[i] == b2) count++;
    //         else if(b2== -1) {b2=fruits[i]; count++;}
    //         else {
    //             count=2;
    //             b1 = fruits[i-1];
    //             b2 = fruits[i];
    //         }
    //         ans = max(ans,count);
    //     }
    //     return ans;
    // }

    int totalFruit(vector<int>& fruits){
        unordered_map<int,int> map;

        int ans=1;
        int n=fruits.size();
        int i=0, j=0;
        while(i<n){
            map[fruits[i]]++;
            if(map.size() <= 2) ans = max(ans, i-j+1);
            else{
                if(map[fruits[j]] == 1) map.erase(fruits[j]);
                else map[fruits[j]]--;
                j++;
            }
            i++;
        }
        return ans;
    }
};
