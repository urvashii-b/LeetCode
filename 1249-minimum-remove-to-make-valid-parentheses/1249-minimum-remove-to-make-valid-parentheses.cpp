class Solution {
public:
    string minRemoveToMakeValid(string s) { 
        int cnt = 0;
        vector<char> arr(s.begin(),s.end());
        // First pass: mark excess closing parentheses with '*'
        for(int i=0;i<arr.size();i++){
            if(arr[i]=='('){
                cnt++;
            }else if(arr[i]==')'){
                if(cnt==0){
                    arr[i]='*';
                }else{
                    cnt--;
                }
            }
        }
        // Second pass: mark excess opening parentheses from the end
        for(int i=arr.size()-1;i>=0;i--){
            if(cnt>0 && arr[i]=='('){
                arr[i]='*';
                cnt--;
            }
        }
        string ans="";
        for(char c: arr){
            if(c!='*'){
                ans+=c;
            }
        }
        return ans;
    }
};