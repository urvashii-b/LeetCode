class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(128,0);
        int counter=0, begin=0, end=0, ans=0;
        while(end<s.size()){
            if(mpp[s[end++]]++>0){
                counter++;
            }
            while(counter>0){
                if(mpp[s[begin++]]-->1){
                    counter--;
                }
            }
            ans = max(ans, end-begin);
        }
        return ans;
    }
};