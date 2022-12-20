tring decodeHuffmanData(struct MinHeapNode* root, string s)
{
    string ans = "";
    struct MinHeapNode* curr = root;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '0') curr= curr->left;
        else curr = curr-> right;
        
        if(!curr->left && !curr->right){
            ans += curr->data;
            curr=root;
        }
    }
    return ans;
    
}
