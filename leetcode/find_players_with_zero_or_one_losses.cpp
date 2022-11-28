class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // vector<vector<int>> ans(2);
        // set<int> wins;
        // map<int,int> loss;
        // for(auto &m : matches){
        //     wins.insert(m[0]);
        //     loss[m[1]]++;
        // }
        // for(int p : wins) if(loss.find(p) == end(loss)) ans[0].push_back(p);
        // for(auto [p,l] : loss) if(l==1) ans[1].push_back(p);
        // return ans;

        //using set difference, doesn't work for some reason ?
        // set<int> all, l, l2;
        // vector<int> a0,a1;
        // for(auto &m : matches){
        //     all.insert({m[0],m[1]});
        //     if(!l.insert(m[1]).second) l2.insert(m[1]);
        // }

        // set_difference(begin(all),end(all), begin(l),end(l),back_inserter(a0));
        // set_difference(begin(l),endl), begin(l2),end(l2),back_inserter(a1));
        // return {a0,a1};


        //yet again a map solution
        vector<vector<int>> ans(2);
        map<int,int> map;
        for(auto & it : matches){
            if(map.find(it[0])==map.end()) map[it[0]]=0;
            map[it[1]]++;
        }
        for(auto &[player,loses] :map){
            if(loses==0) ans[0].push_back(player);
            else if(loses==1) ans[1].push_back(player);
        }
        return ans;
    }
};
