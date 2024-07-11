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
    int maxDepth(TreeNode* root) {
        /*
        
        RECURSIVE
        if(!root) return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);
        return max(maxRight,maxLeft)+1;
        
        
        BFS
        */
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int d=0;
        while(!q.empty()){
            int n = q.size();
            d++;
            for(int i=0;i<n;i++){
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left!=NULL) q.push(ele->left);
                if(ele->right!=NULL) q.push(ele->right);
            }
        }
        return d;
    }
};