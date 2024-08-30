class Solution {
private:
    bool hasDuplicate(string &s, string &t){
        int arr[26] = {0}; 
        
        for(char &c:s){
            if(arr[c-'a']>0){
                return true;
            }
            arr[c-'a']++;
        }
        for(char &c:t){
            if(arr[c-'a']>0){
                return true;
            }
        }
        return false;
    }
    
    int solve(int index, string temp, int n, vector<string>& arr){
        if(index>=n){
            return temp.length();
        }
        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[index],temp)){
            exclude = solve(index+1,temp,n,arr);
        }else{
            exclude = solve(index+1,temp,n,arr);
            include = solve(index+1,temp+arr[index],n,arr);
        }
        return max(include,exclude);
    }
public:
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        int i = 0;
        return solve(0,temp,n,arr);
    }
};