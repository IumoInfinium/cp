class Solution {
public:
    string minimumString(string a, string b, string c) {
        pair<int, string> ans = {305, ""};
        
        auto helper = [&](string a, string b, string c){
            string curr = a;
            
            if(curr.find(b) != string::npos){
                if(curr.find(c) != string::npos){
                    ans = min(ans, {(int) curr.size(), curr});
                }
                else{
                    int common_size = 0;
                    for(int i=1; i<= min((int)curr.size(), (int) c.size()); i++){
                        if(curr.substr(curr.size()-i,i)  == c.substr(0,i))
                            common_size = i;
                    }
                    for(int i=common_size; i< c.size(); i++)  curr += c[i];
                    
                    ans = min(ans, {(int) curr.size(), curr});   
                }
            }
            else{
                int common_size_b = 0;
                for(int i=1; i<= min((int)curr.size(), (int)b.size()); i++){
                    if(curr.substr(curr.size()-i,i)  == b.substr(0,i))
                        common_size_b = i;
                }
                for(int i=common_size_b; i< b.size(); i++)  curr += b[i];
                
                if(curr.find(c) != string::npos){
                    ans = min(ans, {(int) curr.size(), curr});
                }
                else{
                    int common_size_c = 0;
                    for(int i=1; i<= min((int)curr.size(), (int) c.size()); i++){
                        if(curr.substr(curr.size()-i,i)  == c.substr(0,i))
                            common_size_c = i;
                    }
                    for(int i=common_size_c; i<c.size(); i++)  curr += c[i];
                    
                    ans = min(ans, {(int) curr.size(), curr});   
                }
            }
        };
        helper(a,b,c);
        helper(a,c,b);
        helper(c,a,b);
        helper(c,b,a);
        helper(b,c,a);
        helper(b,a,c);
        return ans.second;
    }
};
