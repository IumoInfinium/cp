/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* makeTree(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd){
        if(rowStart > rowEnd || colStart > colEnd) return nullptr;

        bool isLeaf=true;
        int val = grid[rowStart][colStart];

        for(int i=rowStart; i<=rowEnd; i++){
            for(int j=colStart; j<=colEnd; j++){
                if(grid[i][j] != val){
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf) break;
        }
        if(isLeaf) return new Node(val, true);

        int centreRow = (rowStart + rowEnd)/2;
        int centreCol = (colStart + colEnd)/2;

        Node *topLeft = makeTree(grid, rowStart,centreRow, colStart, centreCol);
        Node *topRight = makeTree(grid, rowStart, centreRow, centreCol+1, colEnd);
        Node *bottomLeft = makeTree(grid, centreRow+1, rowEnd, colStart, centreCol);
        Node *bottomRight = makeTree(grid, centreRow+1, rowEnd, centreCol+1, colEnd);
        return new Node(false,false, topLeft, topRight, bottomLeft, bottomRight);
    
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return makeTree(grid, 0, n-1, 0, n-1);
    }
};
