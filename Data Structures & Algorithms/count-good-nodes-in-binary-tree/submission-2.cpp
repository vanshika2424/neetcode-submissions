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
        int res= (root->val>=maxval)? 1:0;
        maxval=max(maxval,root->val);
        int left=countgood(root->left,maxval);
        int right=countgood(root->right,maxval);
       
        return left+right+res;

    }

    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
            
        }
        int maxval=INT_MIN;
        return countgood(root,maxval);
        
        
    }
};
