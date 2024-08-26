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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int width = 0;
        if(root==NULL) return width;
        q.push({root,0});
        while(!q.empty()){
            int n = q.size();
            int max_index = INT_MIN, min_index = INT_MAX;
            while(n--){
                 auto it = q.front();
                q.pop();
                TreeNode* node = it.first;
                int dist = it.second;
                max_index = max(max_index,dist);
                min_index = min(min_index,dist);
                if(node->left) q.push({node->left,(long long)2*dist+1});
                if(node->right) q.push({node->right,(long long)2*dist+2});
            }
            width = max(width,max_index-min_index+1);
        }
        return width;
    }
};