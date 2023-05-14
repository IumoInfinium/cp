class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> players(n+1,false);
        int curr=0, t=1;
        while(!players[curr]){
            players[curr]=true;
            curr += t*k;
            t++;
            curr%=n;
        }
        vector<int> losers;
        for(int i=0; i<n; i++){
            if(players[i] == false) losers.push_back(i+1);
        }
        return losers;
    }
};
