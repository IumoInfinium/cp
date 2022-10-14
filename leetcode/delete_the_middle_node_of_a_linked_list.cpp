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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* tmp=head;
        while(tmp!=NULL){
            tmp=tmp->next;
            n++;
        }
        if(n==1) return NULL;
        tmp=head;
        ListNode *p;
        int x=n/2;
        while(x--){
            p=tmp;
            tmp=tmp->next;
        }
        if(tmp->next !=NULL) p->next=tmp->next;
        else p->next=NULL;
        tmp=NULL;
        // cout<<tmp->val;
        return head;
    }
};
