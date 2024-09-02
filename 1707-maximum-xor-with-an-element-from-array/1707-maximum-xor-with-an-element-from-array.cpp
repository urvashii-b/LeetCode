// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<int> ans;
//         for(int i=0;i<queries.size();i++){
//             int q1 = queries[i][0];
//             int q2 = queries[i][1];
            
//             int maxXor = -1;
//             for(int j=0; j<nums.size(); j++){
//                 if(nums[j]<=q2){
//                     maxXor = max(maxXor, nums[j]^q1);
//                 }
//             }
//             ans.push_back(maxXor);
//         }
//         return ans;
//     }
// };

struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    
    void put(int bit, Node* node){
        links[bit] = node;
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
    
        void insert(int num){
            Node* temp = root;
            for(int i=31; i>=0; i--){
                int bit = (num>>i) & 1;
                if(!temp->containsKey(bit)){
                    temp->put(bit, new Node());
                }
                temp = temp->get(bit);
            }
        }
    
        int findMax(int num){
            Node* temp = root;
            int maxNum = 0;
            for(int i=31; i>=0; i--){
                int bit = (num>>i)&1;
                if(temp->containsKey(1-bit)){
                    maxNum = maxNum | 1<<i;
                    temp=temp->get(1-bit);
                }else{
                    temp=temp->get(bit);
                }
            }
            return maxNum;
        }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(), 0); 
        vector<pair<int, pair<int,int>>> offlineQueries;
        sort(arr.begin(), arr.end()); 
        int index = 0;
        for(auto &it: queries) {
            offlineQueries.push_back({it[1],{it[0], index++}}); 
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0; 
        int n = arr.size(); 
        Trie trie; 

        for(auto &it : offlineQueries) {
           
            while(i < n && arr[i] <= it.first) {
                trie.insert(arr[i]); 
                i++; 
            }

            if(i != 0) 
                ans[it.second.second] = trie.findMax(it.second.first); 
            else 
                
                ans[it.second.second] = -1; 
        }
        
        return ans;
    }
};