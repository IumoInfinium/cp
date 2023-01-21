class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(ans,s,0,"",0);
        return ans;
    }

    void dfs(vector<string>& ans, string& s, int idx, string path, int count){
        if(count >4 ) return;
        if(count ==4 && idx >= s.length()){
            path.pop_back();
            ans.push_back(path);
            return;
        }

        for(int i=1;i<=3 && idx+i <=s.length(); i++){
            string tmp=s.substr(idx,i);
            if(tmp[0]=='0' && i!=1) break;
            else if(stol(tmp) <= 255)
                dfs(ans,s,idx+i,path+s.substr(idx,i)+".",count+1);
        }
    }
};
