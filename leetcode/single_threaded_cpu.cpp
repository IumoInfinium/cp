class Solution {
    typedef pair<int,int> T;
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue< T, vector<T>, greater<>> pq;
        long n=tasks.size();
        long time=0, i=0;
        for(int i=0;i<n;i++) tasks[i].push_back(i);

        sort(begin(tasks),end(tasks));
        vector<int> ans;
        while(i<n || pq.size()){
            if(pq.empty()) time = max(time,(long)tasks[i][0]);

            while(i<n && time>= tasks[i][0]){
                pq.emplace(tasks[i][1],tasks[i][2]);
                i++;
            }
            auto [prop,idx] = pq.top();
            pq.pop();
            time+=prop;
            ans.push_back(idx);
        }
        return ans;
    }
};
