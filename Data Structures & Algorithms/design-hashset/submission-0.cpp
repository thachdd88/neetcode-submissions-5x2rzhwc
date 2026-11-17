class MyHashSet {
public:
    MyHashSet() {
        set_.fill(false);
    }
    
    void add(int key) {
        set_[key] = true;
    }
    
    void remove(int key) {
        set_[key] = false;
    }
    
    bool contains(int key) {
        return set_[key];
    }
private:
    array<bool, 1000001U> set_;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */