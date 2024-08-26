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
    void helper(Node* node, vector<int> &res){
        if(node==NULL) return;
        for(Node* child: node->children){
            helper(child,res);
        }
        res.push_back(node->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root==NULL) return res;
        
        helper(root,res);
        return res;
    }
};