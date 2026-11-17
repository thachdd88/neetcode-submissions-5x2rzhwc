class MyHashMap {
public:
    MyHashMap() {
        set_.fill(-1);
    }
    
    void put(int key, int value) {
        set_[key] = value;
    }
    
    int get(int key) {
        return set_[key];
    }
    
    void remove(int key) {
        set_[key] = -1;
    }
private:
    array<int, 1000001U> set_;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */