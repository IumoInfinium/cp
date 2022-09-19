/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
void helper(LLNode *x){
    if(x!=NULL && x->next!=NULL){
        swap(x->val,x->next->val);
        helper(x->next->next);
    }
}

LLNode* solve(LLNode* node) {
    if(!node) return node;
    helper(node);
    return node;
}
