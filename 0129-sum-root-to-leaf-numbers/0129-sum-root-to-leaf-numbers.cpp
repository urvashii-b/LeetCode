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
    int dfs(TreeNode* curr, int sum){
        if(!curr){
            return 0;
        }
        sum = sum*10+curr->val;
        if(!curr->left && !curr->right){
            return sum;
        }
        return dfs(curr->left, sum)+dfs(curr->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};