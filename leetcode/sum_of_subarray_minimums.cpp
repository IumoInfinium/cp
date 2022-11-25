#define min(a,b)(a < b? a: b)
class Solution {
public:
    // Can do this, but TLE !
    // int sumSubarrayMins(vector<int>& arr) {
    //     int n=arr.size();
    
    //     long long ans=0,prev=0;
    //     for(int i=0;i<n;i++){
    //         prev=arr[i];
    //         ans+= prev;
    //         for(int j=i+1;j<n;j++){
    //             prev = min(prev,arr[j]);
    //             ans+=prev;
    //         }
    //     }
    //     return (ans%1000000007);
    // }

    // Using Montone Stack
    // How to do it? Find PLE (prev less element) & NLE (next prev element) for each element
    // Find the distance of those from element... let's say m and n
    // so total distance including element becomes m+n-1.. total subarrays possible for it are
    // calculate it using formula n*(n+1)/2 making it....S0=  (m+n-1)*(m+n)/2
    // for PLE's left side, we have m-sized array and n-sized array, so their individual all subarrays become.....S1 = m*(m-1)/2   and S2=n*(n-1)/2;
    // And so total subarrays without our element = S0 - S1- S2, which gives m*n;
    // so total arrays for a element(x) which it is minimum are x*m*n
    // in more generalized form.... arr[i]*mi*ni;
    // and we just need it for every element and get it's sum
    int sumSubarrayMins(vector<int> & arr){
        int len=arr.size();
        int ans=0, mod=1e9+7;

        stack<int> st;
        long m,n;
        for(int i=0;i<=len;i++){
            while(!st.empty() && (i == len || arr[st.top()] >= arr[i])){
                int idx= st.top();
                st.pop();
                
                m = st.empty() ? idx+1 : idx-st.top();
                n = i < len ? i-idx : len-idx;

                ans = (ans + m*n*arr[idx])%mod;
            }
            st.push(i);
        }
        return ans;
    }
};
