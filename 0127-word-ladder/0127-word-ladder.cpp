class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord)==wordSet.end()) return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        wordSet.erase(beginWord);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string cur = q.front().first;
                int level = q.front().second;
                q.pop();
                
                if(cur==endWord) return level;
                for(char c='a';c<='z';c++){
                    for(int i=0; i<cur.length(); i++){
                        string neighbor = cur;
                        neighbor[i]=c;
                        if(wordSet.find(neighbor)!=wordSet.end()){
                            q.push({neighbor,level+1});
                            wordSet.erase(neighbor);
                        }
                    }
                }
            }
        }
        return 0;
    }
};