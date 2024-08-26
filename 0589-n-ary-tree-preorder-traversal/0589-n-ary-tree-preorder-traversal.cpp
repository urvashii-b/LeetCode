/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void helper(Node* root, vector<int> &res){
        if(root==NULL) return;
        res.push_back(root->val);
        for(Node* child: root->children){
            helper(child,res);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root==NULL) return res;
        helper(root,res);
        return res;
    }
};