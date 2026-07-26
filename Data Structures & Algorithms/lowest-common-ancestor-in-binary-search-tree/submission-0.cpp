/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        // if(root->val==p) return p;
        // if(root->val==q) return q;
        // if(lowestCommonAncestor(root->left,p,q)!=NULL && lowestCommonAncestor(root->right,p,q)!=NULL){
        //     return root;
        // }
        // else if()
        if((p->val<=root->val && q->val>=root->val) ||(p->val>=root->val && q->val<=root->val)) return root;
        else if(p->val<=root->val && q->val<=root->val){
            return lowestCommonAncestor(root->left,p,q);

        }
        else{
            return lowestCommonAncestor(root->right,p,q);
        }
        
    }
};
