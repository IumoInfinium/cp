class Solution {
public:
    // int find(int i, vector<int>& map){
    //     if(map[i]==i) return i;
    //     return find(map[i]-'a',map);
    // }
    // string smallestEquivalentString(string s1, string s2, string baseStr) {
    //     vector<int> map(26);
    //     for(int i=0;i<26;i++) map[i]=i;
    //     int n = s1.size();
    //     int tmp;
    //     for(int i=0;i<n;i++){
    //         if(s1[i]<s2[i]){
    //             tmp = s1[i]-'a';
    //             if(map[s2[i]-'a'] > tmp)
    //                 map[s2[i]-'a']=tmp;
    //         }
    //         else{
    //             if(map[s1[i]-'a'] > tmp)
    //                 map[s1[i]-'a']=tmp;
    //         }
    //     }
    //     n = baseStr.size();
    //     string ans;
    //     for(int i=0;i<n;i++){
    //         int pos= find(baseStr[i]-'a',map);
    //         ans += ('a'+pos);
    //     }
    //     return ans;
    // }
    string smallestEquivalentString(string s1, string s2, string baseStr){
        char map[26];
        for(int i=0;i<26;i++) map[i]='a'+i;
        int n=s1.size();

        char change, changeTo;
        for(int i=0;i<n;i++){
            change = max(map[s1[i]-'a'], map[s2[i]-'a']);
            changeTo= min(map[s1[i]-'a'], map[s2[i]-'a']);

            for(int i=0;i<26;i++)
                if(map[i] == change)
                    map[i]=changeTo;
        }
        n=baseStr.size();
        for(int i=0;i<n;i++)
            baseStr[i] = map[baseStr[i]-'a'];
        
        return baseStr;
    }
};
