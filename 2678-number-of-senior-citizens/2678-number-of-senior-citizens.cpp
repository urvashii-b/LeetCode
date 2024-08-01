class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(string s:details){
            int age = stoi(s.substr(11,2));     // string to integer
            if(age>60){
                cnt++;
            }
        }
        return cnt;
    }
};