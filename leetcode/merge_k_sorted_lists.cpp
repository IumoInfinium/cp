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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto list : lists){
            ListNode *curr = list;
            while(curr){
                pq.push(curr->val);
                if(curr)curr = curr->next;
            }
        }
        ListNode *prev= new ListNode(-1);
        ListNode *head= prev;
        while(!pq.empty()){
            ListNode* curr = new ListNode(pq.top());
            pq.pop();
            prev->next = curr;
            prev = curr;
        }
        return head->next;
    }
};
