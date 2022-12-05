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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow,*fast;
        slow=head;
        fast=head->next;
        int n=0;
        while(slow!=NULL){
            n+=1;
            slow=slow->next;
        }
        slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=(fast->next)->next;
        }
        if(n&1) return slow;
        else return slow->next;
    }
};
