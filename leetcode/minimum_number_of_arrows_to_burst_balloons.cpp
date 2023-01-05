class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        int back = points[0][1];
        sort(begin(points),end(points));

        for(int i=0;i< points.size(); i++){
            if(points[i][0] > back){
                ans++;
                back = points[i][1];
            }
            else back= min(back,points[i][1]);
        }
        return ans;
    }
};
