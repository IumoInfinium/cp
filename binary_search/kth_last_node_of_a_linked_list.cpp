/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node, int k) {
    LLNode* p1,*p2, *head;
    p1=node, p2=node;
    k++;
    while(k--)p1=p1->next;
    while(p1!=NULL){
        p1=p1->next;
        p2=p2->next;
    }
    return p2->val;
}
