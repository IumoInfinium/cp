class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int w, h;
        if(bx1 > ax2 || bx2 < ax1) w=0;
        else w = min(ax2,bx2)-max(ax1,bx1);
        
        if(by1 > ay2 || by2 < ay1) h=0;
        else h = min(ay2,by2)-max(ay1,by1);

        // w - width of overlapping rectangle
        // h - height of overlapping rectangle
        int area = abs(ax1-ax2)*abs(ay1-ay2) + abs(bx1-bx2)*abs(by1-by2) - abs(w*h);
        return area;
    }
};
