#include <bits/stdc++.h>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int num1=0,num2=0;
    ListNode *tmp1,*tmp2;
    tmp1=l1;
    tmp2=l2;
    int unit1=0,unit2=0;
    while(tmp1!=NULL && tmp2!=NULL){
        num1+=(pow(10,unit1)*tmp1->val);
        num2+=(pow(10,unit2)*tmp2->val);
        tmp1=tmp1->next;
        unit1++;
        tmp2=tmp2->next;
        unit2++;
    }
    int res=num1+num2;
    ListNode *head,*tmp,*p,*prev;
    tmp= new ListNode();
    head=tmp;

}
int main(){
    return 0;
    ListNode *tmp.*l1,=addTwoNumbers(l1,);

    while(addTwoNumbers)
}