// 379. Design Phone Directory [M]
// LeetCode design-phone-directory

class PhoneDirectory {
public:
    unordered_set<int> slots;
    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; i ++) slots.insert(i);
    }
    
    int get() {
        if(slots.size() == 0) return -1;
        int slot = *(slots.begin());
        slots.erase(slot);
        return slot;
    }
    
    bool check(int number) {
        return slots.contains(number);
    }
    
    void release(int number) {
        slots.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */