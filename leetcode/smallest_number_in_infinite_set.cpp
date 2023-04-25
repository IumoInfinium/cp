class SmallestInfiniteSet {
public:
    set<int> sett;
    int small;
    SmallestInfiniteSet() {
        small=1;
    }
    
    int popSmallest() {
        if(!sett.empty()){
            int x = *sett.begin();
            sett.erase(sett.begin());
            return x;
        }
        return small++;
    }
    
    void addBack(int num) {
        if(num < small) sett.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

