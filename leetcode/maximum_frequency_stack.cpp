class FreqStack2 {
public:
    priority_queue<pair<int, pair<int,int>>> pq;
    unordered_map<int, int> freq;
    int pos=0;
    FreqStack2() {
        pos = 0;
    }
    
    void push(int val) {
        pq.emplace(++freq[val], make_pair(++pos, val));    
    }
    
    int pop() {
        auto x = pq.top();
        pq.pop();
        freq[x.second.second]--;
        return x.second.second;
    }
};

class FreqStack{
public:
    vector<vector<int>> freqStates;
    unordered_map<int,int> freq;

    FreqStack() {}

    void push(int val){
        int f = ++freq[val];
        if(f > freqStates.size()){
            freqStates.emplace_back();
        }
        freqStates[f-1].emplace_back(val);
    }

    int pop(){

        // highest freq element near the top of stack at that point 
        int x = freqStates.back().back();
        freqStates.back().pop_back();

        if(freqStates.back().empty()) freqStates.pop_back();
        if(--freq[x] == 0) freq.erase(x);

        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
