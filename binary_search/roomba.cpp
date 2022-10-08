bool solve(vector<string>& moves, int x, int y) {
    // int currx=0,curry=0;
    // for(string dir:moves){
    //     if(dir=="NORTH")     curry++;
    //     else if(dir=="SOUTH")curry--;
    //     else if(dir=="EAST") currx++;
    //     else                 currx--;
    // }
    // return (currx==x && curry==y)?true: false;

    for(string dir:moves){
        if(dir=="NORTH")     y--;
        else if(dir=="SOUTH")y++;
        else if(dir=="EAST") x--;
        else                 x++;
    }
    return (!x&& !y)?true: false;


}
