class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // return (edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])? edges[0][0] : edges[0][1];
        unordered_map<int,int> deg;
        for(vector<int> &edge: edges){
            deg[edge[0]]++;
            deg[edge[1]]++;
        }
        for(pair<int,int> nodes:deg){
            int node = nodes.first;
            int nodeDeg = nodes.second;
            if(nodeDeg == edges.size()){
                return node;
            }
        }
        return -1;
    }
};