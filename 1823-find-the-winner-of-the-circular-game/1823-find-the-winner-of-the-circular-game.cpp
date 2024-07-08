class Solution {
public:
    int findTheWinner(int n, int k) {
        // Josephus Problem
        
        vector<int> circle; // 1 - n
        for(int i=1;i<=n;i++){
            circle.push_back(i);
        }
        int start = 0;
        while(circle.size()>1){
            int remove = (start + k - 1)%circle.size();
            circle.erase(circle.begin()+remove);
            start = remove;
        }
        return circle.front();
    }
};