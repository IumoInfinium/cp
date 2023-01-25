class Solution {
public:
    void dfs(int node,int steps, vector<int>& edges, vector<int>& dist){    
        while(node != -1 && dist[node] == -1){
            dist[node] = steps++;
            node = edges[node];
        }
        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        /*
        Idea -- Use 2 BFS/DFs for both node1 and node2.
        In this case BFS/DFS are same, as a node as only 1 directed neighbour.
        With 2 auxillary arrys that store max and min from from nodes
        and then iterate over the data-structure to get the nodes satisfying these confitions 
        */
        // important note- no need to use adj. list as, 1 node as only 1 edge outwards.
        int n = edges.size();   // number of nodes

        vector<int> dist1(n,-1), dist2(n,-1);
        
        dfs(node1,0,edges,dist1); // distance from node1
        dfs(node2,0,edges,dist2); // distance from node2

        int ans=-1;
        int min_dist=INT_MAX;
        for(int i=0;i<n;i++){
            if(min(dist1[i], dist2[i]) >=0  && max(dist1[i],dist2[i]) < min_dist){
                min_dist = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};
