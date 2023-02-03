//# define CHECK_STATE if(i==s.length()) break;
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         string arr[numRows];
//         int n = s.length();
//         int i=0,j;
//         while(i < n){
//             for(int j=0; j<numRows; j++){
//                 arr[j] += s[i];
//                 i++;
//                 if(i == n) break;
//             }
//             if(i==n) break;
//             for(int j=(numRows - 2); j>0; j--){
//                 arr[j] += s[i];
//                 i++;
//                 if(i == n) break;
//             }
//         }
//         string ans=s;
//         int k=0;
//         for(int i=0; i<numRows; i++){
//             for(int j=0; j<arr[i].length(); j++){
//                 ans[k] = arr[i][j];
//                 k++;
//             }
//         }
//         return ans;
//}
//};
class Solution {
public:
    string convert(string s, int numRows) {
        string arr[numRows];
        int n = s.length();
        int i=0,j;
        while(i < n){
            for(int j=0; j<numRows; j++){
                arr[j] += s[i];
                i++;
                if(i == n) break;
            }
            if(i==n) break;
            for(int j=(numRows - 2); j>0; j--){
                arr[j] += s[i];
                i++;
                if(i == n) break;
            }
        }
        string ans=s;
        int k=0;
        for(int i=0; i<numRows; i++){
            for(int j=0; j<arr[i].length(); j++){
                ans[k] = arr[i][j];
                k++;
            }
        }
        return ans;
    }
};