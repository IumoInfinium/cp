class SummaryRanges {
private:
    set<int> interval;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        interval.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int start = -1, end = -1;

        for(const auto& item : interval){
            if(start == -1){
                start = item;
                end = item;
            }
            else if(item == end + 1) end = item;
            else{
                ans.push_back({start,end});
                start = end = item;
            }
        }
        if(start != -1) ans.push_back({start,end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
