class Solution {
public:
    // recursion based, window checking
    // string gcdOfStrings(string s1, string s2) {
    //     if(s1.length() < s2.length()) swap(s1,s2);

    //     int n=s1.length();
    //     int m=s2.length();
    //     // m < n
        
    //     int i=0;
    //     for(; i<m; i++)
    //         if(s1[i] != s2[i]) return "";
        
    //     if(n == m && i==m) return s2;
    //     return gcdOfStrings(s1.substr(i), s2);
    // }

    // iterative window checking
    // gives runtime error for string memory comparing
    // string gcdOfStrings(string s1, string s2){
    //     int mini = min(s1.size(), s2.size());
    //     int maxi = 0;
        
    //     for(int i=1; i<=mini; i++){
    //         bool found = false;
    //         if((s1.size()%i) == 0 && (s1.size()%i) ==0  && s1.substr(0,i) == s2.substr(0,i)){
    //             found = true;
    //             for(int j=i; j<s1.size(); j+=i){
    //                 if(memcmp(s1.c_str(), s1.c_str()+j, i) != 0){
    //                     found = false;
    //                     break;
    //                 }
    //             }
    //             if(!found) continue;

    //             for(int j=i; j<s2.size(); j+=i){
    //                 if(memcmp(s2.c_str(),s2.c_str()+j, i) != 0){
    //                     found = false;
    //                     break;
    //                 }
    //             }
    //         }
    //         if(found) maxi = i;
    //     }
    //     return s1.substr(0,maxi);
    // }
    string gcdOfStrings(string& s1, string& s2){
        return (s1+s2 == s2+s1) ? s1.substr(0,gcd(s1.length(), s2.length())) : "";
    }
};
