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
    pair<int,int>solve(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int>lh=solve(root->left);
        pair<int,int>rh=solve(root->right);
        int d=lh.first+rh.first;
        
        int h=max(lh.first,rh.first)+1;
        return {h,max(d,max(rh.second,lh.second))};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int maxd=0;
        pair<int,int>ans=solve(root);
        return ans.second;

        
    }
};
