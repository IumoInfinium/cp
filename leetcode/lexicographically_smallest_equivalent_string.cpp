class Solution {
public:
    vector<int> map;

    int find(int i){
        if(map[i]==-1)
            return map[i]=i;
        while(map[i] != i){
            map[i]= map[map[i]];
            i = map[i];
        }
        return i;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map.resize(26,-1);
        int n = s1.size();
        int a,b,x,y;
        for(int i=0;i<n;i++){
            a= s1[i]-'a';
            b= s2[i]-'a';
            x = find(a);
            y = find(b);
            if(x!=y){
                if(x > y){
                    swap(a,b);
                    swap(x,y);
                }
                map[y]=map[x];
                find(a);
                find(b);
            }
        }
        n = baseStr.size();
        for(int i=0;i<n;i++)
            baseStr[i] = (char)('a'+find(baseStr[i]-'a'));
        
        return baseStr;
    }
    // string smallestEquivalentString(string s1, string s2, string baseStr){
    //     char map[26];
    //     for(int i=0;i<26;i++) map[i]='a'+i;
    //     int n=s1.size();

    //     char change, changeTo;
    //     for(int i=0;i<n;i++){
    //         change = max(map[s1[i]-'a'], map[s2[i]-'a']);
    //         changeTo= min(map[s1[i]-'a'], map[s2[i]-'a']);

    //         for(int i=0;i<26;i++)
    //             if(map[i] == change)
    //                 map[i]=changeTo;
    //     }
    //     n=baseStr.size();
    //     for(int i=0;i<n;i++)
    //         baseStr[i] = map[baseStr[i]-'a'];
        
    //     return baseStr;
    // }
};
