class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = 0;
        
        auto lambda = [&](int sum, vector<int> v){
            int n = v.size();
            sum += v[row];
            if(row!=(n-row-1)){
                sum += v[n-row-1];
            }
            row++;
            return sum;
        };
        
        int res = accumulate(mat.begin(), mat.end(), 0, lambda);
        return res;
    }
};