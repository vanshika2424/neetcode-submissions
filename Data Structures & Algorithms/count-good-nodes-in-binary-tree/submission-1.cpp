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
    int countgood(TreeNode* root,int maxval){
        if(root==NULL){
            return 0;
        }
        
        int left=countgood(root->left,max(maxval,root->val));
        int right=countgood(root->right,max(maxval,root->val));
        if(root->val>=maxval){
            return 1+left+right;
        }
        return left+right;

    }

    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
            
        }
        int maxval=INT_MIN;
        return countgood(root,maxval);
        
        
    }
};
