class Solution {
public:
    // string removeStars(string s) {
    //     int n=s.size();
    //     unordered_set<int> pos;
    //     for(int i=n-1; i>=0; i--){
    //         if(s[i]!= '*' || pos.count(i)) continue;
    //         if(s[i] == '*'){
    //             int j= i-1;
    //             for(; j>=0; j--){
    //                 if(pos.count(j)) continue;
    //                 if(s[j] !='*' && !pos.count(j)) break;
    //             }
    //             pos.insert(i);
    //             pos.insert(j);
    //         }
    //     }
    //     string ans="";
    //     for(int i=0;i<n;i++)
    //         if(!pos.count(i)) ans+=s[i];
    //     return ans;
    // }
    
    // string removeStars(string s){
    //     int n = s.size();
    //     stack<char> st;
    //     int i=0;
    //     while(i<n){
    //         if(s[i] != '*') st.push(s[i++]);
    //         else{
    //             st.pop();
    //             i++;
    //         }
    //     }
    //     string ans="";
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //         st.pop();
    //     }
    //     reverse(begin(ans),end(ans));
    //     return ans;
    // }

    string removeStars(string s){
        string ans = "";
        for(char c: s){
            if(c != '*') ans+=c;
            else ans.pop_back();
        }
        return ans;
    }
};
