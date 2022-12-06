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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> values;
        ListNode *tmp=head;
        while(tmp!=NULL){
            values.push_back(tmp->val);
            tmp=tmp->next;
        }
        tmp=head;
        int i=0;
        while(i<values.size()){
            tmp->val = values[i];
            tmp=tmp->next;
            i+=2;
        }
        i=1;
        while(i<values.size()){
            tmp->val = values[i];
            tmp=tmp->next;
            i+=2;
        }
        return head;

    }
};
