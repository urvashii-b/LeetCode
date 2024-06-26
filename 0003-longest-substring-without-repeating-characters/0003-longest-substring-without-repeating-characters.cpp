class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(128,0);
        int counter=0, begin=0, end=0, ans=0;
        while(end<s.size()){
            mpp[s[end]]++;
            while (mpp[s[end]] > 1) {
                mpp[s[begin]]--;
                begin++;
            }

            ans = max(ans, end - begin + 1);
            end++;
        }

        return ans; 
    }
};