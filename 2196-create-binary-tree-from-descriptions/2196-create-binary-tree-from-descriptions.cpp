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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> children;
        unordered_map<int,TreeNode*> nodemap;
        for(const auto& desc: descriptions){
            int parentVal = desc[0];
            int childVal = desc[1];
            bool isLeft = desc[2];
            if(nodemap.count(parentVal)==0){
                nodemap[parentVal] = new TreeNode(parentVal);
            }
            if(nodemap.count(childVal)==0){
                nodemap[childVal] = new TreeNode(childVal);
            }
            if(isLeft){
                nodemap[parentVal]->left = nodemap[childVal];
            }else{
                nodemap[parentVal]->right = nodemap[childVal];
            }
            children.insert(childVal);
        }
        for(auto &entry: nodemap){
            auto &val = entry.first;
            auto &node = entry.second;
            if(children.find(val)==children.end()){
                return node;
            }
        }
        return nullptr; // never reaches here
    }
};