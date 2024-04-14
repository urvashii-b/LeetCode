class Solution {
private:
    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col=1;col<row;col++){
            ans = ans * (row-col);
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        /* 
        (r-1)
            C
             (c-1)
        */
        vector<vector<int>> final;
        for(int i=1;i<=numRows;i++){
            final.push_back(generateRow(i));
        }
        return final;
    }
};