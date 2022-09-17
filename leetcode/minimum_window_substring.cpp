class Solution {
public:
    string minWindow(string s, string t) {
        int m[256]={0};        //Frequency storage
        int ans=INT_MAX;    //Ending index
        int count=0;    //Unique elements
        int start=0;    //Starting position
        
        for(int i=0;i<t.length();i++){          // Updating frequency and unique count
            if(m[t[i]]==0) count++;
            m[t[i]]++;
        }
        
        int i=0;
        int j=0;
        while(j<s.length()){    
            m[s[j]]--;
            if(m[s[j]]==0) count--;
            if(count==0){
                while(count==0){
                    if(ans>j-i+1){              //Updaing the start and end index of the window
                        ans=min(ans,j-i+1);
                        start=i;
                    }
                    m[s[i]]++;                      //Sliding window to next position
                    if(m[s[i]]>0) count++;
                    i++;
                }
            }
            j++;
        }
        if(ans!=INT_MAX) return s.substr(start,ans);            //Returns substring if ans != INT_MAX
        else return "";
    }
};
