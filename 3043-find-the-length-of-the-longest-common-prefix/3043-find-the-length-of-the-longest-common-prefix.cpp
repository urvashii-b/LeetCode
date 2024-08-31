class Solution {
private:
    int findCommonPrefixLength(string &s1, string &s2){
        int i=0;
        while(i<s1.length() && i<s2.length() && s1[i]==s2[i]){
            i++;
        }
        return i;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        vector<string> str1(arr1.size());
        vector<string> str2(arr2.size());
        transform(arr1.begin(), arr1.end(), str1.begin(), [](int num) { return to_string(num); });
        transform(arr2.begin(), arr2.end(), str2.begin(), [](int num) { return to_string(num); });
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        int maxLength = 0;
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            int commonLength = findCommonPrefixLength(str1[i], str2[j]);
            maxLength = max(maxLength, commonLength);
            if (str1[i] < str2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return maxLength;
    }
};