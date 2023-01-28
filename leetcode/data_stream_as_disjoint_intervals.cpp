class SummaryRanges {
// private:
//     set<int> interval;
// public:
//     SummaryRanges() {
        
//     }
    
//     void addNum(int value) {
//         interval.insert(value);
//     }
    
//     vector<vector<int>> getIntervals() {
//         vector<vector<int>> ans;
//         int start = -1, end = -1;

//         for(const auto& item : interval){
//             if(start == -1){
//                 start = item;
//                 end = item;
//             }
//             else if(item == end + 1) end = item;
//             else{
//                 ans.push_back({start,end});
//                 start = end = item;
//             }
//         }
//         if(start != -1) ans.push_back({start,end});
//         return ans;
//     }


// Solution 2------------------------
private:
    map<int,int> intervals;
public:
    SummaryRanges() {}
    
    void addNum(int value){
        int start = value, end = value;
        auto moving_end = intervals.upper_bound(value);

        if(moving_end != intervals.begin()){
            auto moving_start = moving_end;
            --moving_start; 

            if(moving_start->second >= value) return;
            if(moving_start->second == value-1) start = moving_start->first;
        }
        if(moving_end != intervals.end() && moving_end->first == value+1){
            end = moving_end->second;
            intervals.erase(moving_end);
        }

        intervals[start] = end;
    }

    vector<vector<int>> getIntervals(){
        vector<vector<int>> ans;

        for(const auto &item : intervals){
            ans.push_back({item.first, item.second});
        }
        return ans;
    }

};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
