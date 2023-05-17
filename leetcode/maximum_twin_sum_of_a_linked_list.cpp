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
    // int pairSum1(ListNode* head) {
    //     if(head == NULL) return 0;

    //     vector<int> nodes;
    //     ListNode* tmp = head;

    //     while(tmp!= NULL){
    //         nodes.emplace_back(tmp->val);
    //         tmp = tmp->next;
    //     }
    //     int i=0;
    //     int n = nodes.size();
    //     int ans = INT_MIN;
    //     while(i<= (n/2-1)){
    //         ans = max(ans, nodes[i] + nodes[n-i-1]);
    //         i++;
    //     }

    //     return ans;
    // }


    int pairSum(ListNode* head){
        if(head == NULL) return 0;

        stack<int> st;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            st.push(slow->val);
            slow = slow->next;
            fast= fast->next->next;
        }
        int ans = INT_MIN;
        while(slow != NULL){
            ans = max(ans, st.top() + slow->val);
            slow = slow->next;
            st.pop();
        }
        return ans;
    }
};
