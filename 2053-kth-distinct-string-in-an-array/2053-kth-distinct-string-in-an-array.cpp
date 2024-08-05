class Solution {
// private:
//     vector<string> findDistinct(vector<string> &arr){
//         vector<string> res;
//         unordered_map<string,int> freq;
//         for(const auto& s: arr){
//             freq[s]++;
//         }
//         for(const auto& s: arr){
//             if(freq[s]==1){
//                 res.push_back(s);
//             }
//         }
//         return res;
//     }
public:
    string kthDistinct(vector<string>& arr, int k) {
        // vector<string> ans = findDistinct(arr);
        // if(k>0 && k<=ans.size()){
        //     return ans[k-1];
        // }
        // return "";
        unordered_map<string,int> freq;
        for(const auto& s: arr){
            freq[s]++;
        }
        for(const auto& s: arr){
            if(freq[s]==1){
                k--;
            }
            if(k==0){
                return s;
            }
        }
        return "";
    }
};