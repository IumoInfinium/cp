class Solution1 {
public:
    #define ff first
    #define ss second 
    struct compare{
        bool operator()(pair<int,int>& p, pair<int,int>& q){
            return p.ff*p.ff + p.ss*p.ss  > q.ff*q.ff + q.ss*q.ss;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<vector<int>> ans;

        for(auto& p : points){
            pq.push(make_pair(p[0],p[1]));
        }

        while(pq.size()){
            ans.push_back({pq.top().ff, pq.top().ss});
            pq.pop();
            if(ans.size() == k) break;
        }
        return ans;
    }
};

class Solution {
public:
    #define ff first
    #define ss second 
    struct compare{
        bool operator()(pair<int,int>& p, pair<int,int>& q){
            return p.ff*p.ff + p.ss*p.ss  < q.ff*q.ff + q.ss*q.ss;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, compare> pq;
        vector<vector<int>> ans;

        for(auto& p : points){
            pq.push(make_pair(p[0],p[1]));
            if(pq.size() > k) pq.pop();
        }

        while(pq.size()){
            ans.push_back({pq.top().ff, pq.top().ss});
            pq.pop();
            if(ans.size() == k) break;
        }
        return ans;
    }
};
