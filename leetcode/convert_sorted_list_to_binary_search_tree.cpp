/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        while(head!=NULL){
            arr.push_back(head->val);
            head = head->next;
        }
        TreeNode *root = makeTree(0,arr.size()-1, arr);
        return root;
    }

    TreeNode* makeTree(int low, int high, vector<int>& arr){
        if(low> high) return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = makeTree(low, mid-1,arr);
        node->right= makeTree(mid+1,high,arr);
        return node;
    }
};
