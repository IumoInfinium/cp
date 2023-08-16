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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        vector<ListNode*> smallers;

        ListNode* curr = head;

        while(curr){
            if(curr->val < x) smallers.push_back(curr);
            curr = curr->next;
        }
        curr= head;
        while(curr){
            if(curr->val >= x) smallers.push_back(curr);
            curr = curr->next;
        }
        int n = smallers.size();
        for(int i=0; i<n;i++){
            if( i== n-1) smallers[i]->next = NULL;
            else{
                smallers[i]->next = smallers[i+1];
            }
        }
        return smallers[0];
    }
};
