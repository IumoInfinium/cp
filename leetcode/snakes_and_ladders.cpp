class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        if(n==2) return 1;
        vector<vector<bool>> visited(n,vector<bool>(n,false));

        queue<int> q;
        q.push(1);

        int steps=0;

        int curr_pos, next_pos, r, c;
        visited[n-1][0]=true;
        while(!q.empty()){
            int qsize = q.size();
            while(qsize--){
                curr_pos = q.front();
                if(curr_pos == n*n) return steps;
                q.pop();
                for(int i=1; i<=6; i++){        // dice possibilities 1 to 6
                    next_pos = curr_pos+i;
                    if(next_pos > n*n) break;
                    
                    r = n - (next_pos-1)/n -1;  // row of board
                    c = (next_pos-1)%n;         // column of board
                    if(r%2 == n%2)
                        c = n-c-1;
                    if(visited[r][c]) continue;

                    visited[r][c] = true;
                    if(board[r][c]!=-1)
                        q.push(board[r][c]);
                    else 
                        q.push(next_pos);
                }
            }
            steps++;
        }
    return -1;
    }
};
