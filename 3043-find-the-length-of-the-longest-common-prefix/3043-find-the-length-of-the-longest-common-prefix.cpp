class Solution {
public:
    class Node{
        public:
            Node* digits[10];
    };
    
    void add(Node* head, int num){
        string s = to_string(num);
        Node* temp = head;
        for(auto c: s){
            if(!temp->digits[c-'0']){
                temp->digits[c-'0'] = new Node();
            }
            temp = temp->digits[c-'0'];
        }
    }
    
    int check(Node* head, int num){
        Node* temp = head;
        string t = to_string(num);
        int len = 0;
        for(auto c:t){
            if(temp->digits[c-'0']){
                len++;
            }else{
                break;
            }
            temp = temp->digits[c-'0'];  
        }
        return len;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Node* head = new Node();
        for(auto num:arr1){
            add(head,num);
        }
        for(auto num:arr2){
            ans = max(ans,check(head,num));
        }
        return ans;
    }
};