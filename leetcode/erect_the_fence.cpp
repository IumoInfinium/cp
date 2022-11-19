class Solution {
public:
    static const int orient(vector<int>& a,vector<int>& b,vector<int>& c){
        double v = a[0]*(b[1] - c[1]) + b[0]*(c[1] - a[1]) + c[0]*(a[1] - b[1]);
        if(v < 0) return -1;   // clockwise direction... right side not needed in convex hull
        if(v > 0) return 1;    // anti-clockwise direction... left side, needed in convex hull
        return 0;               // points in collinear
    }

    bool cw(vector<int>& a,vector<int>& b,vector<int>& c, bool include_collinear){
        int o = orient(a,b,c);
        return o < 0 || (include_collinear && o ==0);
    }

    // checks if 3 points are collinear or not.
    bool collinear(vector<int>& a,vector<int>& b,vector<int>& c){
        return orient(a,b,c) == 0 ;
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        bool include_collinear = true;

        // find the minimum coodinate y-based, if multiple find min_y,min_x respectively...
        // lowest coordinate near origin
        vector<int> p0 = *min_element(
            trees.begin(),trees.end(), [](vector<int>& a, vector<int>& b){
                return make_pair(a[1],a[0]) < make_pair(b[1],b[0]);
            }
        );
        sort(trees.begin(), trees.end(), [&p0](vector<int>& a,vector<int>& b){
            int o = orient(p0,a,b);
            if( o == 0)
                return (p0[0]-a[0])*(p0[0]-a[0])  + (p0[1]-a[1])*(p0[1]-a[1])
                    <  (p0[0]-b[0])*(p0[0]-b[0])  + (p0[1]-b[1])*(p0[1]-b[1]);
            return o < 0;
        });
        if(include_collinear){
            int i = (int) trees.size()-1;
            while(i>=0 && collinear(p0, trees[i],trees.back())) i--;
            reverse(trees.begin()+i+1, trees.end());
        }

        vector<vector<int>> st;
        for(int i=0; i< (int)trees.size(); i++){
            while( st.size() > 1 && !cw(st[st.size()-2], st.back(), trees[i],include_collinear))
                st.pop_back();
            st.push_back(trees[i]);
        }
        return st;
    }
};
