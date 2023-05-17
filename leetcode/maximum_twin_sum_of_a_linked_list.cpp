class Solution {
public:
    int pairSum(ListNode* head) {
        if(head == NULL) return 0;

        vector<int> nodes;
        ListNode* tmp = head;

        while(tmp!= NULL){
            nodes.emplace_back(tmp->val);
            tmp = tmp->next;
        }
        int i=0;
        int n = nodes.size();
        int ans = INT_MIN;
        while(i<= (n/2-1)){
            ans = max(ans, nodes[i] + nodes[n-i-1]);
            i++;
        }

        return ans;
    }
};
