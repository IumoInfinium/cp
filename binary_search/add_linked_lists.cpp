/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode* solve(LLNode* l0, LLNode* l1) {
    LLNode *dummy = new LLNode();
    LLNode *tmp=dummy;
    int sum,c=0;
    while(l0 !=NULL || l1 !=NULL || c){
        sum=0;
        if(l0!=NULL){
            sum += l0->val;
            l0=l0->next;
        }
        if(l1!=NULL){
            sum += l1->val;
            l1=l1->next;
        }
        sum+=c;
        c=sum/10;
        LLNode *node= new LLNode();
        node->val=sum%10;
        tmp->next=node;
        tmp= tmp->next;
    }
    return dummy->next;
}
