class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {
        int dy = points[1][1] - points[0][1];
        int dx = points[1][0] - points[0][0];

        for(int i=2; i<points.size(); i++){
            if(dx*(points[i][1] - points[0][1]) !=  dy*(points[i][0] - points[0][0])) return false;
        }
        return true;
    }
};
