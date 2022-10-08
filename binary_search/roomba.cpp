bool solve(vector<string>& moves, int x, int y) {
    int currx=0,curry=0;
    for(string dir:moves){
        if(dir=="NORTH")     curry++;
        else if(dir=="SOUTH")curry--;
        else if(dir=="EAST") currx++;
        else                 currx--;
    }
    return (currx==x && curry==y)?true: false;
}
