class Solution {
private:
    void solve(vector<string> &res, string &temp, int index, string &digits, unordered_map<char,string> &mpp){
        if(index>=digits.size()){
            res.push_back(temp);
            return;
        }
        char c = digits[index];
        string s = mpp[c];
        for(int i=0;i<s.length();i++){
            temp.push_back(s[i]);
            solve(res,temp,index+1,digits,mpp);
            temp.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        unordered_map<char,string> mpp;
        mpp['2']="abc";
        mpp['3']="def";
        mpp['4']="ghi";
        mpp['5']="jkl";
        mpp['6']="mno";
        mpp['7']="pqrs";
        mpp['8']="tuv";
        mpp['9']="wxyz";
        vector<string> res;
        string temp = "";
        solve(res,temp,0,digits,mpp);
        return res;
    }
};