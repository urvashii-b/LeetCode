class Solution {
public:
    int findTheWinner(int n, int k) {
        // Josephus Problem
        /*
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
        return circle[0];
        */
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()!=1){
            for(int i=1;i<=k-1;i++){
                q.push(q.front());
                q.pop();
            }
            q.pop(); // losers of each round
        }
        return q.front();
    }
};