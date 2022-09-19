class Solution {
public:
    
    int dp[100];            // for METHOD 2
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // // Method - 1 starts ------------------------------------------
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         int maxSum = INT_MIN;
        
//         for(int l = 0; l < cols; l++){
//             vector<int> sums(rows);         //Kadane's subarray sum
            
//             for(int r = l; r < cols; r++){
//                 int kadane = 0, maxKadane = INT_MIN;
                
//                 for(int i = 0; i < rows; i++){
//                     sums[i] += matrix[i][r];
//                     kadane = max( kadane + sums[i], sums[i]);  
//                     if(kadane == k ) return k;
//                     maxKadane = max( maxKadane , kadane);
//                 }
//                 if( maxKadane <= k){
//                     maxSum = max(maxSum, maxKadane);
//                     continue;
//                 }   
                
//                 set<int> s={0};
                
//                 int runningSum=0;
//                 for(int sum : sums){
//                     runningSum += sum;
//                     auto it = s.lower_bound(runningSum - k);
//                     if(it != s.end()) maxSum = max( maxSum, runningSum - *it);
//                     s.insert(runningSum);
//                 }
//                 if( maxSum == k) return k;
//             }
//         }
//         return maxSum;
        // // Method -1 ends ------------------------------------------------
        
        // // Method -2  starts ------------------------------------------------
        int m = matrix.size();
        int n = matrix[0].size();
        int sum=0;  
        int ans =INT_MIN;
        
        for(int i=0; i<m; i++){
            for(int l=0; l<n; l++) dp[l]=0;
            
            for(int j=i;j<m; j++){
                for(int k=0; k<n; k++){
                    dp[k] += matrix[j][k];     //vertical sum -> row:i~j
                }
                
                for(int a=0 ; a<n; a++){
                    sum=0;
                    for(int b=a; b<n ;b++){
                        sum+=dp[b];             //square sum-> row:i~j, col:a~b
                        if(sum > ans && sum<=k) ans=sum;
                        if(ans == k) return k;
                    }
                }
            }
        }
        return ans;
    }
};
