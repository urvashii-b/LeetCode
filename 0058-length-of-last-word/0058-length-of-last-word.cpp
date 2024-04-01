class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        bool cnt = false;

        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                cnt = true;
                length++;
            }
            else if(cnt){
                break;
            }
        }
        return length;
    }
};