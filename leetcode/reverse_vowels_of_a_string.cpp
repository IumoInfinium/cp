class Solution {
public:
    bool isVowel(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        // unordered_map<char,int> map;
        // map ={{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},
        //       {'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
        // int n = s.size();
        // string t;
        // for(int i=n-1; i>=0;i--){
        //     if(map[s[i]]) t+=s[i];
        // }
        // int j=0;
        // for(int i=0;i<n;i++){
        //     if(map[s[i]]) s[i]=t[j++];
        // }
        // return s;
        // string t=s;
        int low=0, high=s.size()-1;
        while(low<high){
            if(!isVowel(s[low])) low++;
            else if(!isVowel(s[high])) high--;
            else swap(s[low++],s[high--]);
        }
        return s;
    }
};
