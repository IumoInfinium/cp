// class Solution {
// public:
//     int bulbSwitch(int n) {
//         return sqrt(n);
//     }
// };

class Solution {
public:
    int bulbSwitch(int n) {
        int l=1, h=n;
        int ans=0;

        while(l<=h){
            long mid = l +(h-l)/2;
            long sqr = mid*mid;

            if(sqr == n) return (int)mid;
            else if(sqr < n){
                l = mid+1;
                ans = mid;
            }
            else h=mid-1;
        }
        return (int)ans;
    }
};
