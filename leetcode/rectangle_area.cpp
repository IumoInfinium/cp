class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int xx, yy;
        if(bx1 > ax2 || bx2 < ax1)xx=0;
        else xx = min(ax2,bx2)-max(ax1,bx1);
        
        if(by1 > ay2 || by2 < ay1) yy=0;
        else yy = min(ay2,by2)-max(ay1,by1);
        int area=0;
        area += abs(ax1-ax2)*abs(ay1-ay2);
        area += abs(bx1-bx2)*abs(by1-by2);
        area -= abs(xx*yy);
        return area;
    }
};
