class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> item_map;
        
        for(int i=0; i<n; i++)
            item_map[arr[i]].push_back(i);

        vector<bool> visited(n);
        visited[0] = true;
        int curr = 0, qsize = 0, steps = 0;

        queue<int> q;
        q.push(0);

        while(!q.empty()){
            qsize = q.size();
            while(qsize--){
                curr = q.front();
                q.pop();
                if(curr == n-1) return steps;

                // vector<int> options = item_map[arr[curr]];
		vector<int> & options = item_map[arr[curr]];
                options.push_back(curr-1);
                options.push_back(curr+1);

                for(int k : options){
                    if(k>=0 && k <n && !visited[k]){
                        visited[k] = true;
                        q.push(k);
                    }
                }
                // item_map[arr[curr]].clear();
		options.clear();	
            }
            steps++;
        }
        return n-1;
    }
};
