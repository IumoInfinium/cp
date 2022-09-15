class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxStore=0,h;
        int x;
        while(i<j){
            h= height[i] < height[j] ?height[i] : height[j];
            x=(j-i)*h;
            maxStore= x>maxStore? x : maxStore;
            while(i<j && height[i]<=h) i++;
            while(i<j && height[j]<=h) j--;
        }
        return maxStore;
    }
};