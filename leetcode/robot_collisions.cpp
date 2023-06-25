class Solution {
public:
    // vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& health, string dirs) {
    //     vector<int> ids(pos.size());
    //     vector<int> st;

    //     iota(begin(ids), end(ids),0);
    //     sort(begin(ids), end(ids), [&](int i, int j){
    //         return pos[i] < pos[j];
    //     });

    //     for(int id : ids){
    //         if(dirs[id] == 'R') st.push_back(id);
    //         else{
    //             while(!st.empty() && health[id]){
    //                 if(health[id] > health[st.back()]){
    //                     health[st.back()] = 0;
    //                     st.pop_back();
    //                     health[id] -=1;
    //                 }
    //                 else if(health[id] == health[st.back()]){
    //                     health[st.back()] = 0;
    //                     st.pop_back();
    //                     health[id] =0;
    //                 }
    //                 else{
    //                     health[st.back()]--;
    //                     health[id] = 0;
    //                 }
    //             }
    //         }
    //     }
    //     health.erase(remove(begin(health), end(health), 0), end(health));
    //     return health;
    // }

    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& healths, string& dirs){
        int n = pos.size();
        pair<int,int> robots[n];

        for(int i=0; i<n; i++)  robots[i] = make_pair(pos[i],i);
        sort(robots, robots+n);

        stack<int> st;
        for(int i=0; i<n; i++){
            int idx = robots[i].second;

            if(dirs[idx] == 'R') st.push(idx);
            else{
                while(healths[idx]){
                    if(st.empty()) break;
                    
                    if(healths[st.top()] == healths[idx]){
                        healths[st.top()] = healths[idx] = 0;
                        st.pop();
                    }
                    else if(healths[idx] >= healths[st.top()]){
                        healths[idx] -=1;
                        healths[st.top()] = 0;
                        st.pop();
                    }
                    else{
                        healths[st.top()]--;
                        healths[idx]=0;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(healths[i]) ans.push_back(healths[i]);
        }
        return ans;
    }
};
