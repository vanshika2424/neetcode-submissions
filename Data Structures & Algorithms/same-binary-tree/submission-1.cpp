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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if(p==NULL && q==NULL){
        //     return true;
        // }
        // if(p==NULL||q==NULL){
        //     return false;
        // }
        // bool checklefttree=isSameTree(p->left,q->left);
        // bool checkrighttree=isSameTree(p->right,q->right);
        // return (p->val==q->val && checklefttree && checkrighttree);
        queue<TreeNode*>qu;
        qu.push(p);
        qu.push(q);
        while(!qu.empty()){
            TreeNode*root1=qu.front();
            qu.pop();
            TreeNode*root2=qu.front();
            qu.pop();
            if(root1==NULL && root2==NULL){
                continue;
            }
            else if(root1==NULL || root2==NULL){
                return false;
            }
            else{
                if(root1->val==root2->val){
                    qu.push(root1->left);
                    qu.push(root2->left);
                    qu.push(root1->right);
                    qu.push(root2->right);


                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
