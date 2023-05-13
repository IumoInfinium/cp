class MinStack1 {
public:
    stack<int> st;
    map<int,int> mp;
   
    MinStack1() {}
   
    void push(int val) {
        st.push(val);
        mp[val]++;    
    }
   
    void pop() {
        int val = st.top();
        st.pop();
        if(mp.count(val)) mp[val]--;
        if(mp.count(val) && mp[val] == 0) mp.erase(val);
    }
   
    int top() {
        return st.top();
    }
   
    int getMin() {
        return mp.begin()->first;
    }
};

class MinStack{
public:
    stack<int> st;
    stack<int> minStack;
    MinStack(){}


    void push(int val){
        st.push(val);
        if(minStack.empty() || (!minStack.empty() && val<= minStack.top()))
            minStack.push(val);
    }


    void pop(){
        int val = st.top();
        st.pop();
        if(minStack.top() == val) minStack.pop();
    }


    int top(){
        return st.top();
    }


    int getMin(){
        return minStack.top();
    }
};

