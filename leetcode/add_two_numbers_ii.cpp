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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);

        ListNode *dummy, *l3 = new ListNode(-11);
        dummy = l3;

        int carry = 0;

        while(l1 && l2){
            int summ = l1->val + l2->val + carry;
            
            if(summ > 9) carry = 1;
            else carry = 0;

            l1->val = summ % 10;

            l3->next = l1;
            l3 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            l1->val += carry;
            
            if(l1->val > 9) carry = 1;
            else carry = 0;

            l1->val %= 10;
           
            l3->next = l1;
            l3 = l1;
            l1 = l1->next;
        }
        while(l2){
            l2->val += carry;

            if(l2->val > 9) carry = 1;
            else carry = 0;

            l2->val %= 10;

            l3->next = l2;
            l3 = l2;
            l2 = l2->next;
        }
        if(carry){
            ListNode* node = new ListNode(1);
            l3->next = node;
            l3 = node;
        }
        return reverseList(dummy->next);
    }

    ListNode* reverseList(ListNode* node){
        if(!node) return NULL;
        ListNode *prev=NULL, *curr = node, *next;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
