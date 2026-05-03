// 622. Design Circular Queue [M]
// LeetCode design-circular-queue

#include <vector>
#include <atomic>

class MyCircularQueue {
private:
    int capacity;
    std::vector<int> data;
    // 使用 alignas 避免伪共享
    alignas(64) std::atomic<int> head{0};
    alignas(64) std::atomic<int> tail{0};

public:
    MyCircularQueue(int k) : capacity(k + 1), data(k + 1, -1) {}
    
    bool enQueue(int value) {
        int t = tail.load(std::memory_order_acquire);
        int next_t = (t + 1) % capacity;
        
        // 判满：需要看到最新的 head
        if (next_t == head.load(std::memory_order_acquire)) {
            return false;
        }
        
        data[t] = value; 
        
        // 关键：使用 release 语义更新 tail
        // 确保在这之前对 data[t] 的写入对其他线程可见
        tail.store(next_t, std::memory_order_release);
        return true;
    }
    
    bool deQueue() {
        int h = head.load(std::memory_order_acquire);
        
        // 判空：需要看到最新的 tail
        if (h == tail.load(std::memory_order_acquire)) {
            return false;
        }
        
        int next_h = (h + 1) % capacity;
        // 关键：使用 release 语义更新 head
        // 告诉生产者：这个位置的空间已经释放了
        head.store(next_h, std::memory_order_release);
        return true;
    }
    
    int Front() {
        int h = head.load(std::memory_order_acquire);
        if (h == tail.load(std::memory_order_acquire)) return -1;
        return data[h];
    }
    
    int Rear() {
        int t = tail.load(std::memory_order_acquire);
        int h = head.load(std::memory_order_acquire);
        if (h == t) return -1;
        // 经典回退逻辑
        return data[(t - 1 + capacity) % capacity];
    }
    
    bool isEmpty() {
        // 只要 head 等于 tail 就是空
        return head.load(std::memory_order_acquire) == tail.load(std::memory_order_acquire);
    }
    
    bool isFull() {
        int t = tail.load(std::memory_order_acquire);
        int h = head.load(std::memory_order_acquire);
        return (t + 1) % capacity == h;
    }
};