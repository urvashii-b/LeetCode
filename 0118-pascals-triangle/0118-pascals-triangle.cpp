class Solution {
private:
    vector<int> generateRow(int row){
        vector <int> ansRow;
        long long ans = 1;
        ansRow.push_back(ans);
        for(int col=1;col<row; col++){
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
        vector<vector<int>> finalAns;
        for(int i=1;i<=numRows;i++){
            finalAns.push_back(generateRow(i));
        }
        return finalAns;
    }
};