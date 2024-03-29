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
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=dummy;
        dummy->next=head;
        while( head!=NULL && curr!=NULL && head->next!=NULL){
            ListNode *tmp=head->next;
            ListNode *q=tmp->next;
            tmp->next=head;
            head->next=q;
            curr->next=tmp;
            head=head->next;
            curr=curr->next->next;
        }
        return dummy->next;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *dummy = new ListNode();

        ListNode *prev = dummy;
        ListNode *curr = head;

        while(curr && curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr;

            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};
