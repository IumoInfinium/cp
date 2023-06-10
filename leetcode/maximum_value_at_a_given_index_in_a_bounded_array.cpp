class Solution {
public:
    // int maxValue(int n, int index, int maxSum) {
    //     int ans = 1;
    //     int left = index;
    //     int right = index;
    //     int currSum = n;

    //     while(true){
    //         currSum = currSum + (right-left +1);

    //         if(currSum > maxSum) break;
    //         ans++;

    //         if(left > 0) left--;
    //         if(right < n-1) right++;
    //     }
    //     return ans;
    // }

    int maxValue(int n, int index, int maxSum){
        int left = 0;
        int right = maxSum;

        while(left < right){
            int mid = (left+right+1)/2;
            bool isLarge = check(n, index, maxSum-n-mid, mid);

            if(isLarge) left = mid;
            else right= mid-1;
        }
        return left+1;
    }

    bool check(int n, int index, int maxSum, int value){
        
        for(int k=1; maxSum >=0 && k < value && index+k < n; k++) maxSum -= value-k;
        for(int k=1; maxSum >=0 && k < value && index-k >=0; k++) maxSum -= value-k;
        return maxSum >= 0;
    }
};
