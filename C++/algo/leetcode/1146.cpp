// 1146. Snapshot Array [M]
// LeetCode snapshot-array

class SnapshotArray {
    int snapCount = 0;
    vector<vector<pair<int, int>>> dict;
public:
    SnapshotArray(int length) {
        dict.resize(length);
        for(int i = 0; i < length; i ++) {
            dict[i].push_back({0, 0});
        }
    }
    
    void set(int index, int val) {
        dict[index].push_back({ snapCount, val });
    }
    
    int snap() {
        return snapCount ++;
    }
    
    int get(int index, int snap_id) {
        auto& snapList = dict[index];
        int left = 0, right = snapList.size();
        while(left < right) {
            int mid = left + (right - left) /2;
            if(snapList[mid].first >= snap_id + 1) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return snapList[left - 1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */