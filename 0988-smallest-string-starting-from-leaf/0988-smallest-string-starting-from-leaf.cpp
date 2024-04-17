#include<bits/stdc++.h>
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
    string helper(TreeNode*root, string cur){
            cur = cur + string(1,'a'+root->val);
            if(root->left && root->right){
                return min(helper(root->left,cur),helper(root->right,cur));
            }
            if(root->left){
                return helper(root->left,cur);
            }
            if(root->right){
                return helper(root->right,cur);
            }
        reverse(cur.begin(),cur.end());
        return cur;
        }
    
    string smallestFromLeaf(TreeNode* root) {
        return helper(root, "");
    }
};