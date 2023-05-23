// class KthLargest {
// public:
//     multiset<int> msett;
//     int k;
//     KthLargest(int k, vector<int>& nums) {
//         for(int i: nums) msett.insert(i);
//         this->k = k;    
//     }
    
//     int add(int val) {
//         msett.insert(val);

//         if(msett.size() < k) return *msett.end();
//         multiset<int>::iterator it = msett.end();
//         for(int i=0; i<k;i++) it--;
//         return *it;
//     }
// };

class KthLargest{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;

    KthLargest(int k, vector<int>& nums){
        K = k;
        for(int &i: nums){
            pq.push(i);
            if(pq.size()>K) pq.pop();
        }
    }

    int add(int val){
        pq.push(val);
        if(pq.size() > K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
