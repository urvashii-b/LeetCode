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
    void constructPaths(TreeNode* root, string current, vector<string> &paths){
        if(root!=NULL){
            current += to_string(root->val);
            if(root->left==NULL && root->right==NULL){
                paths.push_back(current);
            }else{
                current+="->";
                constructPaths(root->left,current,paths);
                constructPaths(root->right,current,paths);
            }
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == nullptr) return paths;
        constructPaths(root, "", paths);
        return paths;
    }
};