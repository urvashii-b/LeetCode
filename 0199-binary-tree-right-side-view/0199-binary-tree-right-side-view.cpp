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
    void preOrder(TreeNode* root, int level, vector<int> &res){
        if(root==NULL){
            return;
        }
        if(res.size()<level){
            res.push_back(root->val);
        }
        preOrder(root->right,level+1,res);
        preOrder(root->left,level+1,res);
    }
public:
    vector<int> rightSideView(TreeNode* root) {     // level order traversal
        // if(root==NULL) return {};
        // vector<int> res;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()){
        //     int n = q.size();
        //     TreeNode* node = NULL;
        //     while(n--){
        //         node = q.front();
        //         q.pop();
        //         if(node->left!=NULL) q.push(node->left);
        //         if(node->right!=NULL) q.push(node->right);
        //     }
        //     res.push_back(node->val);
        // }
        // return res;
        vector<int> res;
        preOrder(root,1,res);
        return res;
    }
};