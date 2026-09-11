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
    TreeNode*build(int pres,int preend ,int ins,int ine,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&inmap){
        if(pres>preend || ins>ine) return NULL;
        int rootval=preorder[pres];
        TreeNode*root=new TreeNode(rootval);
        int inroot=inmap[rootval];
        int x=inmap[rootval]-ins;
        root->left=build(pres+1,pres+x,ins,inroot-1,preorder,inorder,inmap);
        root->right=build(pres+x+1,preend,inroot+1,ine,preorder,inorder,inmap);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        unordered_map<int,int>inmap;
        for(int i=0;i<n;i++){
            inmap[inorder[i]]=i;
        }
        return build(0,n-1,0,n-1,preorder,inorder,inmap);
        
    }
};
