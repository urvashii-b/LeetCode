struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    
    void put(char c, Node* node){
        links[c -'a'] = node;
    }
    
    Node* get(char c){
        return links[c-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i], new Node());
            }
            temp=temp->get(word[i]);
        }
        temp->setEnd();
    }

    bool search(string word){
        Node* temp = root;
        for(int i=0; i<word.length(); i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->isEnd();
    }

    bool startsWith(string prefix){
        Node* temp = root;
        for(int i=0; i<prefix.length(); i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */