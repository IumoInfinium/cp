class Solution {
public:
    unordered_map<string, bool> mp; 
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0 ;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string a = to_string(nums[i]);
                string b = to_string(nums[j]);
                if((mp.count(a + "," + b) && mp[a+","+b]) ||check(a,b)) ans++;
            }
        }
        return ans;
    }
    
    bool check(string& a, string& b){
        int n1=  a[0]-'0';
        int n2 = b[b.size()-1]-'0';
        
        bool f;
        
        if(__gcd(n1,n2) ==1) f= true;
        else f= false;
        mp[a+","+b] = f;
        return f;
    }
};
