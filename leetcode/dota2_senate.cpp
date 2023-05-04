class Solution {
public:
    string predictPartyVictory(string s) {
        queue<int> qr, qd;
        
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i] == 'R') qr.push(i);
            else qd.push(i); 
        }

        while(!qr.empty() && !qd.empty()){
            int idxP = qr.front(), idxD= qd.front();
            qr.pop(); qd.pop();

            if(idxP < idxD) qr.push(idxP + n);
            else qd.push(idxD +n);
        }

        if(qr.empty()) return "Dire";
        return "Radiant";
    }
};
