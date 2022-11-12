class MedianFinder {
public:
    priority_queue<int> max_pq;
    priority_queue<int,vector<int>,greater<int>> min_pq;
    bool even = true;
    MedianFinder() {}
    
    void addNum(int num) {
        if(!even){
            max_pq.push(num);
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else{
            min_pq.push(num);
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        even =!even;
    }
    
    double findMedian() {
        if(even){
            return double((double)max_pq.top()+(double)min_pq.top())/2.0;
        }
        return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
