/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_set<ListNode*> sett;

    //     ListNode *l1 = headA, *l2 = headB;

    //     while(l1){
    //         sett.insert(l1);
    //         l1= l1->next;
    //     }

    //     while(l2){
    //         if(sett.count(l2)) return l2;
    //         l2 = l2->next;
    //     }
    //     return NULL;
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        ListNode *a = headA;
        ListNode *b = headB;

        while(a != b){
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};
