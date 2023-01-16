class Solution {
public:
    // bool inBetween(int a, int b, int x, int y){
    //     if(a < x && b < x) return false;
    //     if(a > y && b > y) return false;
    //     return true;
    // }
    // vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    //     int n = intervals.size();
    //     vector<vector<int>> ans;

    //     int start = newInterval[0], end = newInterval[1];
    //     bool canMerge=true;
    //     if(n == 0){
    //         ans.push_back({start,end});
    //         return ans;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(intervals[i][0] > end){
    //             if(canMerge) ans.push_back({start,end});
    //             canMerge=false;
    //         }
    //         else if(inBetween(start,end, intervals[i][0], intervals[i][1])){
    //             start = min(start, intervals[i][0]);
    //             end = max(end, intervals[i][1]);
    //             canMerge = true;
    //             continue;
    //         }
    //         ans.push_back({intervals[i]});
    //     }
    //     if(start >= intervals[n-1][1] || canMerge)
    //         ans.push_back({start, end});
        
    //     return ans;
    // }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        int n = intervals.size();
        vector<vector<int>> ans;
        int i=0;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        while(i<n && intervals[i][1] < newInterval[0])
            ans.push_back(intervals[i++]);

        while(i<n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i<n) ans.push_back(intervals[i++]);
        return ans;
    }
};
