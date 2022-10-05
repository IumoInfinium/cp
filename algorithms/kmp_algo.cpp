#include <bits/stdc++.h>
using namespace std;


vector <int> search(string pat, string txt){
    //code hee.
    vector<int> res;
    int n=pat.length();
    int lps[n]={0};
    int start=0;
    // for(int i =1;i<pat.length();i++){
    //     if(pat[start]==pat[i]){
            
    //         lps[i]=start+1;
    //         start++;
    //     }
    //     else{
    //         start=0;
    //         lps[i]=0;
    //     }
    // }
    int i=1;
    while(i<n){
        if(pat[i]==pat[start]){
            start++;
            lps[i]=start;
            i++;
        }
        else{
            if(start!=0) start=lps[start-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    start=0;
    int pat_len=pat.length();
    for(int i=0;i<txt.length();i++){
        if(start<pat_len && txt[i]==pat[start]){
            start++;
            if(start==pat_len){
                res.push_back(i-pat_len+2);
                start=lps[start-1];
                // cout<<"push_back "<<start<<endl;
                // if(txt[i]==pat[start]){
                //     start++;
                //     // cout<<"here";
                // }
            }
        }            
        else if(start<pat_len && pat[start]!=pat[i]){
            // cout<<"here";
                if(start>0)
                    start=lps[start-1];
            // cout<<start<<endl;
        }
    }
    return res;
}
vector<int> search1(string& p, string& s){
        vector<int> res;
        // Creating the Pi table/ Longest Proper Prefix Index array
        // Eg A B A B C
        // pi=[0 0 1 2 0]

        // vector<int> piTable = createPiTable(p);
        int psize = p.size();
        vector<int> piTable(psize);
        piTable[0]=0;
        int i,j;
        for (i = 1; i < n; i++){
            j = piTable[i - 1];
            while (j > 0 && p[i] != p[j])
                j = piTable[j - 1];
            if (p[i] == p[j])
                j++;
            piTable[i] = j;
        }

        i = 0, j = 0;
        int n = s.size();
        int m = p.size();
        while (i < n){
            if (p[j] == s[i]){
                // match found, increment both i & j
                i++;
                j++;
            }
            if (j == m){
                // Pattern found at index i-j
                res.push_back(i - j);
                j = piTable[j - 1];
            }
            else if (i < n && p[j] != s[i]){
                if (j != 0)
                    j = piTable[j - 1];
                else
                    i++; // Check from next position in string s
            }
        }
        return res;
}

int main()
{
    // string s = "ABACABABD";
    string s = "batmanandrobinarebat";
    // string p = "ABA";
    string p = "bat";
    vector<int> res=search(p,s);
    for(int i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}