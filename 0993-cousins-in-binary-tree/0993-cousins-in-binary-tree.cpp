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
    int xdepth, ydepth;
    TreeNode* xparent;
    TreeNode* yparent;
    void depth(TreeNode* root, int x, int y, int dep, TreeNode* par_val){
        if(root==NULL) return;
        if(root->val==x){
            xdepth=dep;
            xparent=par_val;
            return;
        }
        if(root->val==y){
            ydepth=dep;
            yparent=par_val;
            return;
        }
        depth(root->left,x,y,dep+1,root);
        depth(root->right,x,y,dep+1,root);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL || root->val==x || root->val==y) return false;
        depth(root, x, y, 0, 0);
        if(xdepth==ydepth && xparent!=yparent) return true;
        else return false;
    }
};