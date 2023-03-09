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
    ListNode *detectCycle(ListNode *head) {
        ListNode * curr= head;
        unordered_set<ListNode*> sett;
        while(!sett.count(curr)){
            sett.insert(curr);
            if(curr) curr= curr->next;
            else break;
        }
        return curr;
    }
};
