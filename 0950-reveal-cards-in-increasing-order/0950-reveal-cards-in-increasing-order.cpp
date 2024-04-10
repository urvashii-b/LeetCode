class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        /* 
        LOGIC: we need to reveal the odd cards and place even cards in the end,
        the revelation should be alternate and in increasing order of numbers
        
        QUEUE - FIFO: 
        ex: [17,13,11,2,3,5,7]
        */
        int n = deck.size(); 
        vector<int> res(n);
        sort(deck.begin(),deck.end()); // [2,3,5,7,11,13,17] 
           //  ---> to be placed at index:[0,.,1,..,2,..,3] = [2,.,3,.,5,.,7]
           //  ---> others added at the end of the queue
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(i); // pushing all the indexes
        }
        int skip=0,chance=0;
        while(q.size()>0){
            if(skip==0){ // for odd
                res[q.front()]=deck[chance++];
                q.pop();
            }
            else{ // for even
                q.push(q.front()); 
                q.pop();
            }
            skip = abs(skip-1);
        }
        return res;
    }
};