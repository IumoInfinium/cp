int solve(vector<int>& rooms, int target) {
    int res=-1;
    int f=1,i=0;
    for(int i=0;i<(int)rooms.size();i++){
        int tmp=rooms[i];
        if(tmp>=target){res=tmp;
                break;}
    }
    return res;
}
