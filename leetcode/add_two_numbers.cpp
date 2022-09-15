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
        ListNode *head = new ListNode();
        ListNode *prev=head;
        int carry=0;
        while(l1!=NULL && l2!=NULL){
            if(head==NULL){
                int sum=l1->val+l2->val;
                if(sum>9){
                    head->val=sum%10;
                    carry=sum/10;
                }
                else{
                    head->val=sum+carry;
                    carry=0;
                }
                // prev=head;
                cout<<head->val;
            }
            else{
                ListNode *temp = new ListNode();
                int sum=l1->val+l2->val+carry;
                if(sum>9){
                    temp->val=sum%10;
                    carry=sum/10;
                }
                else{
                    temp->val=sum;
                    carry=0;
                }
                prev->next=temp;
                prev=temp;
            }
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l1==NULL && l2!=NULL){
            while(l2!=NULL){
                ListNode *temp = new ListNode();
                int sum=carry+l2->val;
                if(sum>9){
                    temp->val=sum%10;
                    carry=sum/10;
                }
                else{
                    temp->val=sum;
                    carry=0;
                }
                prev->next=temp;
                prev=temp;
                l2=l2->next;
            }
        }
        else if(l2==NULL && l1!=NULL){
            while(l1!=NULL){
                ListNode *temp = new ListNode();
                int sum=carry+l1->val;
                if(sum>9){
                    temp->val=sum%10;
                    carry=sum/10;
                }
                else{
                    temp->val=sum;
                    carry=0;
                }
                prev->next=temp;
                prev=temp;
                l1=l1->next;
            }
        }
        if(carry!=0){
            ListNode *temp = new ListNode();
            temp->val=carry;
            prev->next=temp;                    
        }
        return head->next;
    }
};