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
    vector<int> rightSideView(TreeNode* root) {     // level order traversal
        if(root==NULL) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            TreeNode* node = NULL;
            while(n--){
                node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            res.push_back(node->val);
        }
        return res;
    }
};