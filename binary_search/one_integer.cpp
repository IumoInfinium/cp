int solve(vector<int>& nums) {
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i :nums)
        q.push(i);
    int cost=0,x,y;
    while(q.size()>1){
        x=q.top();
        cout<<x<<endl;
        q.pop();
        y=q.top();
        cout<<y<<endl;
        q.pop();
        q.push(x+y);
        cost+=(x+y);
        // cout<< x+y<<"\n";
    }
    return cost;
}
