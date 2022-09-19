class NumArray {
    vector<int> arr;
    vector<long long> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        while(__builtin_popcount(n)!=1){
            arr.push_back(0);
            n++;
        }
        tree.resize(2*n);
        for(int i=0;i<n;i++){
            tree[n+i]=arr[i];
        }
        for(int i=n-1;i>=1;i--){
            tree[i]=tree[2*i]+tree[2*i+1];
        }
        
    }
    
    void update(int index, int val) {
        int x=n+index;
        int changeVal=val-tree[x];      // ChangedValue from update operation
        tree[x]=val;                     //New Value
        while(x!=0){
            x/=2;
            tree[x]+=changeVal;
        }
    }
    
    long long f(int node,int node_low,int node_high,int query_low, int query_high){
        if(query_low <= node_low && node_high<=query_high) return tree[node];
        if(node_high<query_low || query_high<node_low) return 0;
        int last_from_left= (node_low+node_high)/2;
        
        return f(2*node,node_low,last_from_left, query_low,query_high)
             + f(2*node+1,last_from_left+1,node_high,query_low,query_high);
    }
    
    int sumRange(int left, int right) {
        return f(1,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
