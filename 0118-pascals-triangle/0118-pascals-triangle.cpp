class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ansRows;
        for(int i=1;i<=numRows;i++){
            vector<int> temp;
            int ans = 1;
            temp.push_back(ans);
            for(int j=1;j<i;j++){
                ans = ans * (i-j);
                ans = ans/(j);
                temp.push_back(ans);
            }
            ansRows.push_back(temp);
        }
        return ansRows;
    }
};