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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            double size = q.size(), sum = 0;
            for(int i=0;i<size;i++){
                TreeNode* ele = q.front();
                q.pop();
                sum += ele->val;
                if(ele->left!=NULL) q.push(ele->left);
                if(ele->right!=NULL) q.push(ele->right);
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};