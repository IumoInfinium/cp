/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // const static bool compare(const pair<int,int>&a , const pair<int,int>&b){
    //     if(a.first == b.first) return a.second > b.second;
    //     return a.first < b.first;
    // }
    // int maxLevelSum(TreeNode* root) {
    //     unordered_map<int,int> mp;
    //     helper(0,root, mp); 

    //     vector<pair<int,int>> arr;
    //     for(auto &it : mp){
    //         arr.emplace_back(it.second, it.first);
    //     } 
    //     sort(begin(arr),end(arr), compare); 
    //     return arr[arr.size()-1].second+1;
    // }

    // void helper(int lvl, TreeNode* node, unordered_map<int,int>& mp){
    //     if(!node) return;
    //     mp[lvl] += node->val;

    //     if(node->left) helper(lvl+1, node->left, mp);
    //     if(node->right) helper(lvl+1, node->right, mp);
    //     return;
    // }

    int arr[10000];
    int maxLevels=0;
    int maxLevelSum(TreeNode* root){
        if(!root) return 0;

        int maxSum = INT_MIN;
        int maxSumLevel = 0;
        memset(arr, 0, sizeof(arr));
        
        dfs(root,0);

        for(int i=0; i<= maxLevels; i++){
            if(arr[i] > maxSum){
                maxSum = arr[i];
                maxSumLevel = i;
            }
        }
        return maxSumLevel + 1;
    }

    void dfs(TreeNode* node, int level){
        if(!node) return;

        maxLevels = max(maxLevels,level);
        arr[level] += node->val;
        if(node->left) dfs(node->left, level+1);
        if(node->right) dfs(node->right, level+1);
    }

    // int maxLevelSum(TreeNode* root){
    //     if(!root) return 0;

    //     int maxSum =INT_MIN;
    //     int maxSumLvl = 0;
    //     int lvl=-1;
    //     queue<TreeNode*> q;
    //     q.push(root);

    //     while(!q.empty()){
    //         int qsize = q.size();
    //         TreeNode* node;
    //         int lvlSum=0;
            
    //         lvl++;
    //         while(qsize--){
    //             node = q.front();
    //             q.pop();

    //             if(!node) continue;    
    //             lvlSum += node->val;
    //             if(node->left) q.push(node->left);
    //             if(node->right) q.push(node->right);
    //         }
    //         if(lvlSum > maxSum){
    //             maxSum = lvlSum;
    //             maxSumLvl = lvl;
    //         }
    //     }
    //     return maxSumLvl+1;
    // }
};
