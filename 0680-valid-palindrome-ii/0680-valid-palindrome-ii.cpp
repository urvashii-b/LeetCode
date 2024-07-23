class Solution {
private:
    bool helper(int start, int end, string s, bool chances){
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            }else if(chances){
                return helper(start+1,end,s,false) || helper(start,end-1,s,false);
            }else{
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return helper(0, s.size()-1, s, true);
    }
};