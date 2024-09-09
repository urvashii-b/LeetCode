class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // linear scan
        for(char c: letters){
            if(c>target){
                return c;
            }
        }
        return letters[0];
    }
};