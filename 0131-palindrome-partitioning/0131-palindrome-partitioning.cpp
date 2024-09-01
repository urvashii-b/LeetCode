class Solution {
private:
    bool isPalindrome(int left, int right, string&s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    void solve(string &s, int index, vector<string> &curr, vector<vector<string>> &ans, int n){
        if(index==n){
            ans.push_back(curr);
            return;
        }
        for(int i=index; i<n; i++){
            if(isPalindrome(index,i,s)){
                curr.push_back(s.substr(index,i-index+1));
                solve(s,i+1,curr,ans,n);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.length();
        solve(s,0,curr,ans, n);
        return ans;
    }
};