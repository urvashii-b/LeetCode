/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mpp;
    
    void DFS(Node* node, Node* clone_node){
        for(Node* n: node->neighbors){
            if(mpp.find(n)==mpp.end()){
                Node* clone = new Node(n->val);
                mpp[n] = clone;
                clone_node->neighbors.push_back(clone);
                
                DFS(n,clone);
            }else{
                clone_node->neighbors.push_back(mpp[n]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        mpp.clear();
        Node* clone_node = new Node(node->val);
        mpp[node] = clone_node;
        DFS(node,clone_node);
        return clone_node;
    }
};