class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(); // rows
        int m = mat[0].size();  // cols
        map<int,vector<int>> mpp;
        vector<int> res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        bool flip = true;
        for(auto &it: mpp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto& num: it.second){
                res.push_back(num);
            }
            flip=!flip;
        }
        return res;
    }
};