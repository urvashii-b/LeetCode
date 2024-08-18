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
    string tree2str(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string res = to_string(root->val);
        string leftval = tree2str(root->left);
        string rightval = tree2str(root->right);
        if(root->left==NULL && root->right==NULL){
            return res;
        }
        if(root->left==NULL){
            return res+"()"+"("+rightval+")";
        }
        if(root->right==NULL){
            return res+"("+leftval+")";
        }
        return res+"("+leftval+")"+"("+rightval+")";
    }
};