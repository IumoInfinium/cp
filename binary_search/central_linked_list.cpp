/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
int solve(LLNode* node) {
    if(!node) return 0;
    int n=0;
    LLNode* tmp=node;
    while(node!=NULL){
        if(n&1) tmp=tmp->next;
        n++;
        node=node->next;
    }
    if(tmp!=NULL) return tmp->val;
    return 0;
}
