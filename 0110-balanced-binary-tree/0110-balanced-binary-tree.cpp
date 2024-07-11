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
private:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int maxL = height(root->left);
        int maxR = height(root->right);
        return max(maxL,maxR)+1;
    }
public:
    bool isBalanced(TreeNode* root) {   // for all nodes in the tree, the difference between left and right subtree height is not more than 1.
        if(root==NULL) return true;
        int leftH = height(root->left);
        int rightH = height(root->right);
        if(abs(leftH-rightH)<=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};