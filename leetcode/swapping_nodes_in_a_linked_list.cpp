class Solution {
public:
    ListNode* swapNodes1(ListNode* head, int k) {
        vector<int> vals;
        ListNode* tmp=head;

        while(tmp){
            vals.emplace_back(tmp->val);
            tmp = tmp->next;
        }
        swap(vals[k-1], vals[vals.size()-k]);

        tmp = head;
        int i=0;
        while(tmp){
            tmp->val = vals[i++];
            tmp= tmp->next;
        }
        return head;
    }

    ListNode* swapNodes(ListNode *head, int k){
        if(head == NULL) return head;

        ListNode *slow= head, *fast= head;
        ListNode* node;
        while(--k){
            fast= fast->next;
        }
        node = fast;
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        swap(node->val , slow->val);
        return head;
    }
};
