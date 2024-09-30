class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        unordered_set<string> visited;
        visited.insert(startGene);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string cur = q.front();
                q.pop();
                
                if(cur==endGene){
                    return level;
                }
                for(char c: "ACGT"){
                    for(int i=0; i<cur.length();i++){
                        string neighbor = cur;
                        neighbor[i]=c;
                        if((visited.find(neighbor)==visited.end()) && (bankSet.find(neighbor)!=bankSet.end())){
                            visited.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};