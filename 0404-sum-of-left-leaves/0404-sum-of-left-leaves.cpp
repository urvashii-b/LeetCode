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
    /*
    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, false);
    }
    
    int dfs(TreeNode* node, bool isFalse){
        if(!node){
            return 0;
        }
        if(!node->right && !node->left){
            return isFalse? node->val: 0;
        }
        int leftSum = dfs(node->left, true);
        int rightSum = dfs(node->right, false);
        return leftSum + rightSum;
    }
    */
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        else if(root->left!=nullptr && root->left->left==nullptr && root->left->right==nullptr){ // left leaf
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        else{
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        }
    }
    
};