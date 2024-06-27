class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        /*
        return (edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])? edges[0][0] : edges[0][1];
        */
        int n = edges.size();
        vector<int> mp(n+2,0);
        for(int i=0;i<n;i++){
            mp[edges[i][0]]++;
            mp[edges[i][1]]++;
            if(mp[edges[i][0]]==n) return edges[i][0];
            if(mp[edges[i][1]]==n) return edges[i][1];
        }
        return 0;
    }
};