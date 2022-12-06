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
    // ListNode* oddEvenList(ListNode* head) {
        // vector<int> values;
        // ListNode *tmp=head;
        // while(tmp!=NULL){
        //     values.push_back(tmp->val);
        //     tmp=tmp->next;
        // }
        // tmp=head;
        // int i=0;
        // while(i<values.size()){
        //     tmp->val = values[i];
        //     tmp=tmp->next;
        //     i+=2;
        // }
        // i=1;
        // while(i<values.size()){
        //     tmp->val = values[i];
        //     tmp=tmp->next;
        //     i+=2;
        // }
        // return head;
    // }
    ListNode* oddEvenList(ListNode* head){
        // divide the linked list into 2 groups, odd and even
        // then append even list at the end of odd list
        if(!head || !head->next || !head->next->next) return head;
        ListNode *odd = head;
        ListNode *even= head->next;
        ListNode *even_start= head->next;

        while(odd->next && even->next){
            odd->next = even->next;
            even->next= odd->next->next;
            odd= odd->next;
            even = even->next;
        }
        odd->next = even_start;
        return head;
    }
};
