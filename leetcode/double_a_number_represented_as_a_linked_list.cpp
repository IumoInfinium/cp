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
    ListNode* doubleIt(ListNode* head) {
        if(!head) return NULL;
        head = reverse(head);
        
        ListNode *curr = head;
        ListNode* prev = NULL;
        int carry = 0;
        
        while(curr){
            int val = curr->val;
            val *= 2;
            if(carry) val++;
            if(val > 9) carry = 1;
            else carry = 0;
            
            curr->val = val%10;
            prev = curr;
            curr= curr->next;
        }
        if(carry){
            prev->next = new ListNode(1);
        }
        
        head = reverse(head);
        return head;
        
    }
    
    ListNode* reverse(ListNode *head){
        if(!head) return head;
        
        ListNode* prev=NULL, *curr = head, *next=NULL;
        
        while(curr!= NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
