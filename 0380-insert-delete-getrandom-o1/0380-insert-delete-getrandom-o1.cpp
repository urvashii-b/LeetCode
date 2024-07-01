class RandomizedSet {
private:
    unordered_map<int,int> indices;
    vector<int> values;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(indices.find(val)==indices.end()){
            values.push_back(val);
            indices[val] = values.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(indices.find(val)==indices.end()){
            return false;
        }
        int index = indices[val];
        indices[values[values.size()-1]] = index; // mpp[a[last]]=index
        values[index]=values[values.size()-1];
        values.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()]; // for (x % n), it gives 0....n-1 values
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */